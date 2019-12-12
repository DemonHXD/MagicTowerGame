#include "Config.h"



Config::Config()
{
}


Config::~Config()
{
}

/*
	从配置文件读取
*/
void Config::ReadConfig()
{
	FILE * pFileConfig = fopen("res/game/config.txt", "rb");
	fread(&m_layer, 4, 1, pFileConfig);
	fclose(pFileConfig);
}

/*
	写入到配置文件
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
