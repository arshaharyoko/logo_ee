#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

void drawTopBar( GLfloat x, GLfloat y, GLfloat z );
void drawMiddleBar( GLfloat x, GLfloat y, GLfloat z );
void drawBottomBar( GLfloat x, GLfloat y, GLfloat z );
void drawCircle( GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides );

int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Elektro?", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );

        // render vertices
        drawTopBar( SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2, 0 );
        drawMiddleBar( SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2, 0 );
        drawBottomBar( SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2, 0 );
        drawCircle( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 360, 36 );
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}

void drawTopBar( GLfloat x, GLfloat y, GLfloat z ) 
{   
    GLfloat offsetX = -130;
    GLfloat offsetY = 80;
    // GLfloat vertices[] = {
    //     x, y+100, z, // top left
    //     x+250, y+100, z, // top right
    //     x, y, z, // bottom left
    //     x+300, y, z, // bottom right
    // };

    GLfloat vertices[] = {
        x, y, z,
        x, y, z,
        x, y+40, z,
        x+20, y+20, z,// pusat 1/4 lingkaran

        x+5, y+70, z, 
        x+20, y+20, z,// pusat 1/4 lingkaran

        x+20, y+100, z, 
        x+20, y+20, z,// pusat 1/4 lingkaran

        x+30, y+105, z, 
        x+20, y+20, z,// pusat 1/4 lingkaran

        x+50, y+110, z, 
        x+20, y+20, z,// pusat 1/4 lingkaran

        x+250, y+110, z, // top right 
        x+20, y+20, z,// pusat 1/4 lingkaran

        x+250, y+110, z, // top right
        x+275, y+20, z, // bottom right
    };

    GLint vertexCount = 16;
    GLint numVertices = vertexCount*3;

    // Translate w offset
    for (int i=0;i<numVertices;i+=3) {
        vertices[i] += offsetX;
        vertices[i+1] += offsetY;
    }

    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    glDrawArrays( GL_QUAD_STRIP, 0, vertexCount );
    glDisableClientState( GL_VERTEX_ARRAY );
}

void drawMiddleBar( GLfloat x, GLfloat y, GLfloat z ) 
{   
    GLfloat offsetX = -130;
    GLfloat offsetY = -25;

    GLfloat vertices[] = {
        x, y, z,
        x, y+90, z,
        x+225, y, z,
        x+260, y+90, z, // pusat 1/4 lingkaran

        x+245, y+5, z, 
        x+260, y+90, z, // pusat 1/4 lingkaran

        x+255, y+10, z, 
        x+260, y+90, z, // pusat 1/4 lingkaran

        x+265, y+15, z, 
        x+260, y+90, z, // pusat 1/4 lingkaran

        x+280, y+45, z, 
        x+260, y+90, z, // pusat 1/4 lingkaran
        x+280, y+110, z, 
        x+280, y+110, z, 
    };

    GLint vertexCount = 14;
    GLint numVertices = vertexCount*3;

    //Rotate
    // GLfloat angle = M_PI;
    // GLfloat c = cos(angle);
    // GLfloat s = sin(angle);
    // for (int i=0;i<numVertices;i+=3) {
    //     GLfloat x = vertices[i];
    //     GLfloat y = vertices[i + 1];
    //     vertices[i] = x*c - y*s;
    //     vertices[i+1] += x*s + y*c;
    // }

    //Translate w offset
    for (int i=0;i<numVertices;i+=3) {
        vertices[i] += offsetX;
        vertices[i+1] += offsetY;
    }

    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    glDrawArrays( GL_QUAD_STRIP, 0, vertexCount );
    glDisableClientState( GL_VERTEX_ARRAY );
}

void drawBottomBar( GLfloat x, GLfloat y, GLfloat z ) 
{   
    GLfloat offsetX = -130;
    GLfloat offsetY = -40;
    // GLfloat vertices[] = {
    //     x, y+100, z, // top left
    //     x+250, y+100, z, // top right
    //     x, y, z, // bottom left
    //     x+300, y, z, // bottom right
    // };

    GLfloat vertices[] = {
        x, y, z,
        x, y, z,
        x, y-40, z,
        x+20, y-20, z,// pusat 1/4 lingkaran

        x+5, y-70, z, 
        x+20, y-20, z,// pusat 1/4 lingkaran

        x+20, y-100, z, 
        x+20, y-20, z,// pusat 1/4 lingkaran

        x+30, y-105, z, 
        x+20, y-20, z,// pusat 1/4 lingkaran

        x+50, y-110, z, 
        x+20, y-20, z,// pusat 1/4 lingkaran

        x+250, y-110, z, // top right 
        x+20, y-20, z,// pusat 1/4 lingkaran

        x+250, y-110, z, // top right
        x+275, y-20, z, // bottom right
    };

    GLint vertexCount = 16;
    GLint numVertices = vertexCount*3;

    // Translate w offset
    for (int i=0;i<numVertices;i+=3) {
        vertices[i] += offsetX;
        vertices[i+1] += offsetY;
    }

    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    glDrawArrays( GL_QUAD_STRIP, 0, vertexCount );
    glDisableClientState( GL_VERTEX_ARRAY );
}

void drawCircle( GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides )
{
    GLint numberOfVertices = numberOfSides + 1;
    
    GLfloat doublePi = 2.0f * M_PI;
    
    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];
    
    //circleVerticesX[0] = x;
    //circleVerticesY[0] = y;
    //circleVerticesZ[0] = z;
    
    for ( int i = 0; i < numberOfVertices; i++ )
    {
        circleVerticesX[i] = x + ( radius * cos( i * doublePi / numberOfSides ) );
        circleVerticesY[i] = y + ( radius * sin( i * doublePi / numberOfSides ) );
        circleVerticesZ[i] = z;
    }
    
    GLfloat allCircleVertices[numberOfVertices * 3];
    
    for ( int i = 0; i < numberOfVertices; i++ )
    {
        allCircleVertices[i * 3] = circleVerticesX[i];
        allCircleVertices[( i * 3 ) + 1] = circleVerticesY[i];
        allCircleVertices[( i * 3 ) + 2] = circleVerticesZ[i];
    }
    
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, allCircleVertices );
    glDrawArrays( GL_LINE_STRIP, 0, numberOfVertices );
    glDisableClientState( GL_VERTEX_ARRAY );
}