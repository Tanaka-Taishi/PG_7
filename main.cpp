#include<stdio.h>
#include<iostream>
#include<chrono>

using namespace std;

int main(){

	std::string a(100000, 'a');

	auto CopyStart = std::chrono::high_resolution_clock::now();
	std::string Copystr = a;
	auto CopyEnd = std::chrono::high_resolution_clock::now();
	auto CopyDuration = std::chrono::duration_cast<std::chrono::microseconds>(CopyEnd - CopyStart);


	auto MoveStart = std::chrono::high_resolution_clock::now();
	std::string moveStr = std::move(a);
	auto MoveEnd = std::chrono::high_resolution_clock::now();
	auto MoveDuration = std::chrono::duration_cast<std::chrono::microseconds>(MoveEnd - MoveStart);

	std::cout << "100,000�̕������ړ��ƃR�s�[�Ŕ�r���܂���" << std::endl;
	std::cout << "�R�s�[" << CopyDuration.count() << "��s" << std::endl;
	std::cout << "�ړ�" << MoveDuration.count() << "��s" << std::endl;

}
