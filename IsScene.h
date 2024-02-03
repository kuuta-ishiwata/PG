#pragma once
enum  Scene 
{
	Title,Stage,Clear,Scene

};

class IsScene
{

protected:
	static int sceneNo;
	const char* keys_;
	const char* prekeys_;

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IsScene();

	int GetSceneNo();

	void Setkeys(char* keys, char* prekeys);



};
