#include "Config.h"



Config::Config()
{
}


Config::~Config()
{
}

/*
	�������ļ���ȡ
*/
void Config::ReadConfig()
{
	FILE * pFileConfig = fopen("res/game/config.txt", "rb");
	fread(&m_layer, 4, 1, pFileConfig);
	fclose(pFileConfig);
}

/*
	д�뵽�����ļ�
*/
void Config::WriteConfig()
{
	FILE * pFileConfig= fopen("res/game/config.txt", "wb");
	fwrite(&m_layer, sizeof(int), 1, pFileConfig);
	fclose(pFileConfig);
}

Config::Config(int layer) {
	m_layer = layer;
}
