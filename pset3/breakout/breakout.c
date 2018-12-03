//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// paddle size
#define PADDLEH 20
#define PADDLEW 75

// paddle Y
#define PADDLEY 500

// Ball size
#define BALLSZ 13 

// brick height
#define BRICKH 15

// brick spacing
#define SPACE 4
// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
GLabel initBrickscore(GWindow window);
GLabel initLvLabel(GWindow window);
GLabel initScLabel(GWindow window);
GLabel initBkLabel(GWindow window);
GLabel initLives(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);


int main(void)

{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel score = initScoreboard(window);
    GLabel bricksremain = initBrickscore(window);
    GLabel livesremain = initLives(window);
    GLabel scorelabel = initScLabel(window);
    GLabel bricklabel = initBkLabel(window);
    GLabel liveslabel = initLvLabel(window);
    
    
    

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int scores = 0;

    // initial velocity
    double velocityx = 2.0*drand48();
    double velocityy = 2.0;
    
    
    GLabel start = newGLabel("Click to Begin");
    setFont(start, "SansSerif-40");
    add(window, start);
    setLocation(start, 50, HEIGHT/2);
    
    GLabel fast = newGLabel("The ball moves faster as time goes on!");
    setFont(fast, "SansSerif-20");
    add(window, fast);
    setLocation(fast, 0, HEIGHT/2+50);
    
    
    waitForClick();
    setVisible(start, false);
    setVisible(fast, false);
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
                
        GEvent event = getNextEvent(MOUSE_EVENT);
                
        // if we heard one
        if (event != NULL)
        {
            
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows mouse
                double paddlex = getX(event) - getWidth(paddle)/2;
                setLocation(paddle, paddlex , PADDLEY);
                
                if (getX(event) + getWidth(paddle)/2 > WIDTH)
                {
                    setLocation(paddle, WIDTH - getWidth(paddle), PADDLEY);
                }
                
                else if (getX(event) - getWidth(paddle)/2 < 0)
                {
                     setLocation(paddle, 0, PADDLEY);
                }
            } 
        }
                
        // move circle along x-axis
        move(ball, velocityx, velocityy);
        pause (10);
                            
        //bounce off right edge of window
            if ((getX(ball) + getWidth(ball)) >= getWidth(window))
            {
               velocityx = -velocityx;
               // speeds up ball as game progresses
               velocityx *= 1.0075;
               velocityy *= 1.005;
            }

        //b/ounce off left edge of window
            else if (getX(ball) <= 0)
            {
                velocityx = -velocityx;
                // speeds up ball as game progresses
                velocityx *= 1.0075;
                velocityy *= 1.005;
            }
      
        //bounce of top
            else if (getY(ball) <= 0)
            {
                velocityy = -velocityy;
                // speeds up ball as game progresses
                velocityx *= 1.0025;
                velocityy *= 1.005;
            }
            
        //bounce of bottom
            else if (getY(ball) + getHeight(ball) >= getHeight(window))
            {
                lives--;
                updateScoreboard( window, livesremain, lives);
                if (lives > 0)
                {    
                    setLocation(paddle, (WIDTH-PADDLEW)/2, PADDLEY);
                    setLocation(ball, WIDTH/2, HEIGHT/2);
                    velocityx = 2.0*drand48();
                    velocityy = 2.0;
                    waitForClick();
                }
                
                
                
            } 
            
            
            GObject collision = detectCollision(window, ball);
               
            if (collision != NULL)
            {  
              
                
                if (collision == paddle)
                {
                    velocityy = -velocityy;
                    // speeds up ball as game progresses
                    velocityx *= 1.01;
                    velocityy *= 1.01;
                }
                
                else if (strcmp(getType(collision), "GRect") == 0)
                {
                    bricks--;
                    scores++;
                    velocityy = -velocityy;
                    removeGWindow(window, collision);
                    updateScoreboard( window, bricksremain, bricks);
                    updateScoreboard( window, score, scores);
                    // speeds up ball as game progresses
                    velocityx *= 1.01;
                    velocityy *= 1.01;
                            
                }
                
                else if (strcmp(getType(collision), "GLabel") == 0)
                {
                    
                }
                
            
            }
            
        
    
        
     
    }
    
    if (bricks == 0)
    {
    GLabel youWin = newGLabel("You Win!!!");
    setFont(youWin, "SansSerif-75");
    add(window, youWin);
    setLocation(youWin, 10, HEIGHT/2);
    }
    else
    {
    GLabel youLose = newGLabel("You Lose!!");
    setFont(youLose, "SansSerif-75");
    add(window, youLose);
    setLocation(youLose, 10, HEIGHT/2);
    }
    
    // wait for click before exiting
    waitForClick();
   

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // Makes a brick, different color dending on row, makes a 10 x 5 grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            GRect paddle = newGRect((SPACE/2) + (j*(WIDTH/COLS)),100 + (i * (SPACE + BRICKH)) , (WIDTH/10)-SPACE, BRICKH);
            if (i == 0)
            {
            setColor(paddle, "RED");
            }
            if (i == 1)
            {
            setColor(paddle, "YELLOW");
            }
            if (i == 2)
            {
            setColor(paddle, "MAGENTA");
            }
            if (i == 3)
            {
            setColor(paddle, "PINK");
            }
            if (i == 4)
            {
            setColor(paddle, "ORANGE");
            }
            setFilled(paddle, true);
            add(window, paddle);    
        }
    }
    
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    
    // instantiate ball
    GOval ball = newGOval(WIDTH/2, HEIGHT/2, BALLSZ, BALLSZ);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // Made a rect, color gray and centered it near the bottom.
    GRect paddle = newGRect((WIDTH-PADDLEW)/2, PADDLEY, PADDLEW, PADDLEH);
    setColor(paddle, "GRAY");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 
    GLabel score = initScoreboard(window);
    GLabel bricksremain = initBrickscore(window);
    GLabel livesremain = initLives(window);
    GLabel scorelabel = initScLabel(GWindow window);
    GLabel bricklabel = initBkLabel(GWindow window);
    GLabel liveslabel = initLvLabel(GWindow window);*/
    
GLabel initScoreboard(GWindow window)
{
    
        GLabel score = newGLabel(" ");
        setFont(score, "SansSerif-22");
        add(window, score);
        char scoress [3];
        int scores = 0;
        sprintf(scoress, "%i", scores);
        setLabel(score, scoress);
        setLocation(score, 90, 85);
        return score;
}

GLabel initBrickscore(GWindow window)
{
    
        GLabel bricksremain = newGLabel(" ");
        setFont(bricksremain, "SansSerif-22");
        add(window, bricksremain);
        char brickss [3];
        int bricks = 50;
        sprintf(brickss, "%i", bricks);
        setLabel(bricksremain, brickss);
        setLocation(bricksremain, 90, 55);
        return bricksremain;
}

GLabel initLives(GWindow window)
{
        GLabel livesremain = newGLabel(" ");
        setFont(livesremain, "SansSerif-22");
        add(window, livesremain);
        char livess [2];
        int lives = 3;
        sprintf(livess, "%i", lives);
        setLabel(livesremain, livess);
        setLocation(livesremain, 90, 25);
        return livesremain;
}

GLabel initScLabel(GWindow window)

{
    GLabel scorelabel = newGLabel("Score:");
    setFont(scorelabel, "SansSerif-22");
    add(window, scorelabel);
    setLocation(scorelabel, 10, 85);
    return scorelabel;
}
GLabel initBkLabel(GWindow window)

{
    GLabel bricklabel = newGLabel("Bricks:");
    setFont(bricklabel, "SansSerif-22");
    add(window, bricklabel);
    setLocation(bricklabel, 10, 55);
    return bricklabel;
} 

GLabel initLvLabel(GWindow window)

{
    GLabel liveslabel = newGLabel("Lives:");
    setFont(liveslabel, "SansSerif-22");
    add(window, liveslabel);
    setLocation(liveslabel, 10, 25);
    return liveslabel;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);
}
/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}  
