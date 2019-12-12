#include "Config.h"



Config::Config()
{
}

/*
	���캯��
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
	�������ļ���ȡ
*/
void Config::ReadConfig(Config *&config)
{
	FILE * pFileConfig = fopen("res/game/config.txt", "rb");
	fread(config, sizeof(Config), 1, pFileConfig);
	fclose(pFileConfig);
}

/*
	д�뵽�����ļ�
*/
void Config::WriteConfig(Config *&config)
{
	FILE * pFileConfig = fopen("res/game/config.txt", "wb");
	fwrite(config, sizeof(Config), 1, pFileConfig);
	fclose(pFileConfig);
}

/*
	��ʼ������
*/
void Config::InitConfig() {
	string save[] = { 
		"*        δ�浵һ       *",
		"*        δ�浵��       *",
		"*        δ�浵��       *" 
	};
	Config *config = new Config(0, save);
	FILE * pFileConfig = fopen("res/game/config.txt", "wb");
	fwrite(config, sizeof(Config), 1, pFileConfig);
	fclose(pFileConfig);
}


