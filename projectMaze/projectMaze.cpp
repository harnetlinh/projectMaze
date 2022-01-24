#include "RandomMaze.h"
#include <iostream>
#include "RandomMaze.h"
#include "CrazyRobot.h"
#include "JumpingRobot.h"
#include "ComplexMaze.h"
#include "SmartRobot.h"
#include "VerySmartRobot.h"

int main()
{
    //RandomMaze* rd_maze = new RandomMaze(4, 10, 10, 3);
    ComplexMaze* cpl_maze = new ComplexMaze(15, 15);
    //cpl_maze->display();
    //cout << " -------------------------- " << endl;
    cpl_maze->display();
    //JumpingRobot* jumpingRobot = new JumpingRobot(cpl_maze);
    //CrazyRobot* crazyRobot = new CrazyRobot(cpl_maze);
    //SmartRobot* smartRobot = new SmartRobot(cpl_maze);
    VerySmartRobot* verySmartRobot = new VerySmartRobot(cpl_maze);
    //int JRstep = 0;
    int limit_step = 50;
    //for (; cpl_maze->positionInMaze(jumpingRobot->getCurrentPosition().getX(), jumpingRobot->getCurrentPosition().getY()) != 4 && JRstep < limit_step; ++JRstep)
    //{
    //    jumpingRobot->go();
    //}
    //int CRstep = 0;
    //for (; cpl_maze->positionInMaze(crazyRobot->getCurrentPosition().getX(), crazyRobot->getCurrentPosition().getY()) != 4 && CRstep < limit_step; ++CRstep)
    //{
    //    crazyRobot->go();
    //}
    //int SMstep = 0;
    //for (; cpl_maze->positionInMaze(smartRobot->getCurrentPosition().getX(), smartRobot->getCurrentPosition().getY()) != 4 && SMstep < limit_step; ++SMstep)
    //{
    //    smartRobot->go();
    //}
    int VSMstep = 0;
    for (; cpl_maze->positionInMaze(verySmartRobot->getCurrentPosition().getX(), verySmartRobot->getCurrentPosition().getY()) != 4 && VSMstep < limit_step; ++VSMstep)
    {
        verySmartRobot->go();
    }
    
    //cout <<" JRstep = "<< JRstep << endl;
    //cout << " CRstep = " << CRstep << endl;
    //cout << " SMstep = " << SMstep << endl;
    cout << " VSMstep = " << VSMstep << endl;
}
