#pragma once

#include "ofMain.h"
#include "controllableAgent/controllableAgent.hpp"
#include "heatMap/heatMap.hpp"
#include "enemyVisualField/enemyVisualField.hpp"
#define NODE_D 2
#define EPOCHS pow(10, 4)
#define MAX_RANGE 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

//		void keyPressed(int key);
//		void keyReleased(int key);
//		void mouseMoved(int x, int y );
//		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
//		void mouseReleased(int x, int y, int button);
//		void mouseEntered(int x, int y);
//		void mouseExited(int x, int y);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
    
        ControllableAgent* agents [NODE_D * NODE_D];
    
        // define input neurons
        FloatInputNeuron* x_input = new FloatInputNeuron();
        FloatInputNeuron* y_input = new FloatInputNeuron();
        FloatInputNeuron* io_neuron [2] = {x_input, y_input};
        
        // define feedback query
        FeedbackQueryManager* query_manager = new FeedbackQueryManager();
        
        // define mapping neurons
        FloatMappingNeuron* maps [NODE_D * NODE_D];
    
        // define global operator
        FloatKohonenSOM global_operator = FloatKohonenSOM(maps, NODE_D * NODE_D, 2);
    
        /*
        Heat Map Grid display settings
        */
        HeatMap heat_map = HeatMap(10, 10, 1024,768);
    
        // define enemy position and colliders
        EnemyVisualField enemy_map = EnemyVisualField(1024, 768);
};
