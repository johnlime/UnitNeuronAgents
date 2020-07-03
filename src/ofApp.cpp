#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    
    /*
    Kohonen's Self Organizing Map and Controllable Agent Setup
    */
    
    // allocate memory for mapping neurons and agents
    for (int i = 0; i < NODE_D * NODE_D; i++){ // 2x2 nodes
        FloatMappingNeuron* tmp_n = new FloatMappingNeuron((FloatUnitNeuron**) io_neuron, 2, query_manager, MAX_RANGE);
        ControllableAgent* tmp_a = new ControllableAgent(ofVec2f(50, 50), ofVec3f(255, 255, 255));
        maps[i] = tmp_n;
        agents[i] = tmp_a;
    }
    
    // assign neighboring neurons
    for (int i = 0; i < NODE_D * NODE_D; i++)
    {
        int a, b;
        
        // corners
        if (
            i == 0 ||
            i == NODE_D - 1 ||
            i == NODE_D * (NODE_D - 1) ||
            i == NODE_D * NODE_D - 1
            )
        {
            if (i == 0)
            {
                a = 1;
                b = NODE_D;
            }
            else if (i == NODE_D - 1)
            {
                a = -1;
                b = NODE_D;
            }
            
            else if (i == NODE_D * (NODE_D - 1))
            {
                a = 1;
                b = -NODE_D;
            }
            
            else// if (i == NODE_D * NODE_D - 1)
            {
                a = -1;
                b = -NODE_D;
            }
            
            FloatMappingNeuron** tmp = new FloatMappingNeuron* [2]
            {
                maps[i + a],
                maps[i + b]
            };
            maps[i]->assign_neighbors(tmp, 2);
        }
        
        // edges
        else if (
            i % NODE_D == 0 ||
            i % NODE_D == NODE_D - 1 ||
            int(i / NODE_D) == 0 ||
            int(i / NODE_D) == NODE_D - 1
            )
        {
            // left edge
            if (i % NODE_D == 0)
            {
                a = 1;
                b = NODE_D;
            }
            
            // right edge
            else if (i % NODE_D == NODE_D - 1)
            {
                a = -1;
                b = NODE_D;
            }
            
            // upper edge
            else if (int(i / NODE_D) == 0)
            {
                a = NODE_D;
                b = 1;
            }
            
            // lower edge
            else// if (int(i / NODE_D) == NODE_D - 1)
            {
                a = -NODE_D;
                b = 1;
            }
            
            FloatMappingNeuron** tmp = new FloatMappingNeuron* [3]
            {
                maps[i - b],
                maps[i + a],
                maps[i + b]
            };
            maps[i]->assign_neighbors(tmp, 3);
        }
        
        // default
        else
        {
            a = 1;
            b = NODE_D;
            
            FloatMappingNeuron** tmp = new FloatMappingNeuron* [4]
            {
                maps[i - a],
                maps[i + a],
                maps[i + b],
                maps[i - b]
            };
            maps[i]->assign_neighbors(tmp, 4);
        }
    }
    
    // train self organizing map
    for (int i = 0; i < EPOCHS; i++)
    {
        // feedforward
        io_neuron[0]->assign_value(((float)rand() / RAND_MAX) * 1024);
        io_neuron[1]->assign_value(((float)rand() / RAND_MAX) * 768);
        
        for (int j = 0; j < NODE_D * NODE_D; j++){
            maps[j]->feedforward();
        }
        
        // feedback
        global_operator.execute();
        query_manager->execute_all();
    }
    
    /*
    Heat Map Grid display settings
    */
    
    // grid setup
    // would require object instances that represent individual cells
}

//--------------------------------------------------------------
void ofApp::update(){
    // step forward toward target positions within SOM per agent
    for (int i = 0; i < NODE_D * NODE_D; i++){
        agents[i]->update_target(
            ofVec2f(
                maps[i]->see_memory()[0],
                maps[i]->see_memory()[1])
             );
        agents[i]->move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // if statement
    
        // display controllable agent
        for (int i = 0; i < NODE_D * NODE_D; i++){
            agents[i]->display();
        }
        
        // heat map display version
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    // controllable agent display and heat map display switch
    // (boolean or string variable)
}
