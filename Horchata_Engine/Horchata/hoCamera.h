#pragma once
class hoCamera
{
public:
	hoCamera();
	~hoCamera();


public:
	int x;
	int y;
	int zoom;
	void MoveCamera(float _x, float _y, float _time);
	void MoveCameraLeft(float _velocidad);
	void MoveCameraRight(float _velocidad);
	void ZoomIn(float zoomd);
	void ZoomOut(float zoomd);


};

