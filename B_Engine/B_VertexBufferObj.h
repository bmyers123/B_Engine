#pragma once
class B_VertexBufferObj
{
public:

	B_VertexBufferObj(void);
	~B_VertexBufferObj(void);

	int setUpVBO(unsigned int numVertices, bool useNormals, bool useTexcoords);

	void renderVBO();

	void activateVBO();
	void deactivateVBO();

	void Release();

	int addVerts(float *rawVerts);
	int addNormals(float *rawNorms);
	int addUVs(float *rawUVs);

private:

	unsigned int vertexHandle;
	unsigned int normalHandle;
	unsigned int uvHandle;

	// array handle (VAO)
	unsigned int vaoHandle;
	
	// total number of vertices to be rendered
	unsigned int numVerts;

};

