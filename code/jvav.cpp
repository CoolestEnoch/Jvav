#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

const string jvav_ver = "1.1f";
int execmd(char* cmd, char* result) {
	char buffer[128];                         //定义缓冲区                        
	FILE* pipe = _popen(cmd, "r");            //打开管道，并执行命令 
	if (!pipe)
		return 0;                      //返回0表示运行失败 

	while (!feof(pipe)) {
		if (fgets(buffer, 128, pipe)) {             //将管道输出到result中 
			strcat(result, buffer);
		}
	}
	_pclose(pipe);                            //关闭管道 
	return 1;                                 //返回1表示运行成功 
}

//java

int main(int argc, char* argv[]) {
	//for (int i = 1; i < argc; i += 2) {printf("%s\n%d\n", argv[i], i);}	cout << "\n\n\n";

	bool flag = 0;
	char ver[] = "-version";

	//cout << strlen(ver) << endl << strlen(argv[1]) << endl;

	for (int i = 0; i < strlen(ver); i++)
	{
		if (argv[1][i] == ver[i])
		{
			flag = 1;
			//cout << i;
		}
		else
		{
			flag = 0;
		}
	}

	//cout << flag << endl;

	char s[10000] = {};
	strcat(s, "java ");//=====================java和javac命令
	strcat(s, argv[1]);

	char result[1024 * 4] = "";

	char java_ver_str[] = "javac -version";

	if (flag == 1 && strlen(argv[1]) == strlen(ver))
	{
		if (1 == execmd(java_ver_str, result)) {
			result[0] = ' ';
			result[1] = ' ';
			result[2] = 'j';
			result[3] = 'd';
			result[4] = 'k';
			result[5] = ' ';
			cout << result << endl;
		}
		cout << "jvav version " << jvav_ver << " powered by C++(草" << endl
			<< "Jvav(TM) SE Runtime Environment" << endl
			<< "Jvav HotSpot(TM) 64-Bit Server VM";
		return 0;
	}
	
	if (1 == execmd(s, result)) {
		printf(result);
	}
	

	return 0;
}


//javac
/*
int main(int argc, char* argv[]) {
	//for (int i = 1; i < argc; i += 2) {printf("%s\n%d\n", argv[i], i);}	cout << "\n\n\n";

	bool flag = 0;
	char ver[] = "-version";
	if (strlen(argv[1]) == strlen(ver)) {
		for (int i = 0; i < strlen(ver); i++)
		{
			if (argv[1][i] == ver[i])
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
	}

	char s[10000] = {};
	strcat(s, "javac ");//=====================java和javac命令
	strcat(s, argv[1]);

	char result[1024 * 4] = "";

	if (1 == execmd(s, result)) {
		if(flag == 1){
			result[1] = 'v';
			result[2] = 'a';
			result[3] = 'v';
			printf(result);
			cout << "ver" << jvav_ver << " Powered by C++(草";
		}else{
			printf(result);
		}
	}



	return 0;
}*/
