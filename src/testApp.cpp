#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	shader.load("shaders/depth");
	   
	grabber.initGrabber(640,480);
	fbo.allocate(grabber.getWidth(), grabber.getHeight());
	shader.begin();
	shader.setUniform1f("brightness", 1);
	shader.setUniform1f("contrast", 1);
	shader.setUniform1f("saturation", 0.5);
	shader.setUniform1i("invert",false);
	shader.setUniform1f("alpha", 1.0 );
	shader.setUniformTexture("tex", fbo.getTextureReference(), 1);
	shader.end();
	
	int width = grabber.getWidth();
	int height = grabber.getHeight();
	int step = 5;
	mainMesh.setMode(OF_PRIMITIVE_TRIANGLES);
	//add one vertex to the mesh for each pixel
	for (int y = 0; y < height; y+=step){
		for (int x = 0; x<width; x+=step){
			mainMesh.addVertex(ofPoint(x,y,0));	// mesh index = x + y*width
			// this replicates the pixel array within the camera bitmap...
//			mainMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
			mainMesh.addTexCoord(ofPoint(x,y,0));
			
			mainMesh.addVertex(ofPoint(x+step,y,0));	// mesh index = x + y*width
			// this replicates the pixel array within the camera bitmap...
//			mainMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
			mainMesh.addTexCoord(ofPoint(x+step,y,0));
			
			mainMesh.addVertex(ofPoint(x,y+step,0));	// mesh index = x + y*width
			// this replicates the pixel array within the camera bitmap...
//			mainMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
			mainMesh.addTexCoord(ofPoint(x,y+step,0));
			
			
			mainMesh.addVertex(ofPoint(x+step,y,0));	// mesh index = x + y*width
			// this replicates the pixel array within the camera bitmap...
//			mainMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
			mainMesh.addTexCoord(ofPoint(x+step,y,0));
			
			mainMesh.addVertex(ofPoint(x+step,y+step,0));	// mesh index = x + y*width
			// this replicates the pixel array within the camera bitmap...
//			mainMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
			mainMesh.addTexCoord(ofPoint(x+step,y+step,0));
			
			mainMesh.addVertex(ofPoint(x,y+step,0));	// mesh index = x + y*width
			// this replicates the pixel array within the camera bitmap...
//			mainMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
			mainMesh.addTexCoord(ofPoint(x,y+step,0));
		}
	}
//	for (int y = 0; y<height-1; y+=step){
//		for (int x=0; x<width-1; x+=step){
//			mainMesh.addIndex(x+y*width);				// 0
//			mainMesh.addIndex((x+1)+y*width);			// 1
//			mainMesh.addIndex(x+(y+1)*width);			// 10
//			
//			mainMesh.addIndex((x+1)+y*width);			// 1
//			mainMesh.addIndex((x+1)+(y+1)*width);		// 11
//			mainMesh.addIndex(x+(y+1)*width);			// 10
//		}
//	}
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();
	fbo.begin();
	grabber.draw(0, 0);
	fbo.end();
}	

//--------------------------------------------------------------
void testApp::draw(){
	glPushMatrix();
	glTranslatef(ofGetWidth()*0.5-fbo.getWidth()*0.5, ofGetHeight()*0.5-fbo.getHeight()*0.5, 0);
	shader.begin();
	shader.setUniform1i("maxHeight",mouseX);
//	fbo.draw(0, 0);
//
	fbo.getTextureReference().bind();
	mainMesh.drawFaces();
	fbo.getTextureReference().unbind();
//fbo.unbind();
	shader.end();
	glPopMatrix();
//	mainMesh.drawFaces();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	shader.load("shaders/depth");
	shader.setUniform1i("tex", 0);

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}