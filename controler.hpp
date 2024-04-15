/*
定义了PID控制器以及相关的操作
本人能力有限，难免存在BUG与不完善、可优化的地方，欢迎各位大佬使用与更正！
作者：SamKinGLiiiEeE
个人仓库：https://github.com/Samking-Li
CSDN：https://blog.csdn.net/qq_33994286?type=blog
*/

#pragma once
#include<iostream>
#include <vector>
#include"matplotlibcpp.h" //绘制pid控制曲线依赖matplotlibcpp库，请自行配置。参考：https://zhuanlan.zhihu.com/p/585302210
using namespace std;

class pid
{
private:
	float kp;//比例系数
	float ki;//积分系数
	float kd;//微分系数
	float target;//目标值
	float actual;//实际值
	float e;//误差
	float e_pre;//上一次误差
	float integral;//积分项
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