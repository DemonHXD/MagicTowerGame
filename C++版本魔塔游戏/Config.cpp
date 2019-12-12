#include "Config.h"



Config::Config()
{
}

/*
	构造函数
*/
Config::Config(int layer, string save[]) {
	m_layer = layer;
	for (int i = 0; i < 3; i++)
	{
		m_save[i] = save[i];
	}
}


Config::~Config()
{
}

/*
	从配置文件读取
*/
void Config::ReadConfig(Config *&config)
{
	FILE * pFileConfig = fopen("res/game/config.txt", "rb");
	fread(config, sizeof(Config), 1, pFileConfig);
	fclose(pFileConfig);
}

/*
	写入到配置文件
*/
void Config::WriteConfig(Config *&config)
{
	FILE * pFileConfig = fopen("res/game/config.txt", "wb");
	fwrite(config, sizeof(Config), 1, pFileConfig);
	fclose(pFileConfig);
}

/*
	初始化配置
*/
void Config::InitConfig() {
	string save[] = { 
		"*        未存档一       *",
		"*        未存档二       *",
		"*        未存档三       *" 
	};
	Config *config = new Config(0, save);
	FILE * pFileConfig = fopen("res/game/config.txt", "wb");
	fwrite(config, sizeof(Config), 1, pFileConfig);
	fclose(pFileConfig);
}


