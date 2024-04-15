/*
������PID�������Լ���صĲ���
�����������ޣ��������BUG�벻���ơ����Ż��ĵط�����ӭ��λ����ʹ���������
���ߣ�SamKinGLiiiEeE
���˲ֿ⣺https://github.com/Samking-Li
CSDN��https://blog.csdn.net/qq_33994286?type=blog
*/

#pragma once
#include<iostream>
#include <vector>
#include"matplotlibcpp.h" //����pid������������matplotlibcpp�⣬���������á��ο���https://zhuanlan.zhihu.com/p/585302210
using namespace std;

class pid
{
private:
	float kp;//����ϵ��
	float ki;//����ϵ��
	float kd;//΢��ϵ��
	float target;//Ŀ��ֵ
	float actual;//ʵ��ֵ
	float e;//���
	float e_pre;//��һ�����
	float integral;//������
	vector<float> log;
public:
	pid() :kp(0), ki(0), kd(0), target(0), actual(0), integral(0)
	{
		this->e = this->target - this->actual;
		this->e_pre = this->e;
	}
	pid(float p, float i, float d) :kp(p), ki(i), kd(d), target(0), actual(0), integral(0)
	{
		this->e = this->target - this->actual;
		this->e_pre = this->e;
	}
	void control(float target, float actual)
	{
		float u;
		this->target = target;
		this->actual = actual;
		this->e = this->target - this->actual;
		this->integral += this->e;
		u = this->kp * this->e + this->ki * this->integral + this->kd * (this->e - this->e_pre);
		this->e_pre = this->e;
		this->log.push_back(u);
	}
	void show()
	{
		cout << "The infomation of this position PID controller is as following:" << endl;
		cout << "       Kp=" << this->kp << endl;
		cout << "       Ki=" << this->ki << endl;
		cout << "       Kd=" << this->kd << endl;
		cout << " integral=" << this->integral << endl;
		cout << "   target=" << this->target << endl;
		cout << "   actual=" << this->actual << endl;
		cout << "        e=" << this->e << endl;
		cout << "    e_pre=" << this->e_pre << endl;
	}
	void plot()
	{
		/*LATEST*/
	}
};