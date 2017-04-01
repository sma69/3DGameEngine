#include <jansson.h>


json_t *Model_json_load(char * filename)
{
	json_t *root = NULL;
	json_error_t error;

	root = json_load_file(filename, JSON_DECODE_ANY, &error);
	return root;
}

float *model_json_get_vertices(json_t* model)
{
	float* vertices;
	json_t* vertarray;
	int count = 0;

	if (!model)
	{
		slog("no model");
		return NULL;
	}

	vertarray = json_object_get(model, "uvs");

	

}