#include <iostream>


/**
 * Yêu cau: So nguyen a duoc nhap tu ban phim:
 * Ðem so bit có giá tri 1 va in ra man hinh
 * Viet chuong trinh thay doi giá tri bit thu 4 tu phai qua cua a ve 0 và hien thi ra man hinh gia tri cua bien a.
 * Viet chuong trinh thay doi gia tri bit thu 5 tu phai qua cua a ve 1 và hien thi ra man hinh giá tri cua bien a.
 * Viet chuong trinh dao giá tri bit thu 3 tu phai qua cua a ve 0 và hien thi ra man hinh giá tri cua bien a.
 * Chi su dung Bitwise de thay doi so 0x1234 thành 0x3412 và 0x4321.
 */

int count_ones(int num)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (num & 1) count++;
		num >>= 1;
	}
	return count;
}

int modifyBit(int a, int position, int bit)
{
	int mask = 1 << position;
	return ((a & ~mask) | (bit << position));
}

int main()
{
	int a;
	std::cout << "Nhap so nguyen a:";
	std::cin >> a;
	std::cout << "So bit co gia tri 1 cua a la:" << count_ones(a) << std::endl;
	std::cout << "So a sau khi doi bit thu 4 tu phai qua ve 0 la: " << modifyBit(a, 4, 0) << std::endl;
	std::cout << "So a sau khi doi bit thu 5 tu phai qua ve 1 la: " << modifyBit(a, 5, 1) << std::endl;
	std::cout << "So a sau khi dao bit thu 3 tu phai qua ve 0 la: " << modifyBit(a, 3, 0) << std::endl;
	//Bitwise doi 0x1234 thanh 0x3412 va 0x4321
	int data{ 0x1234 };
	std::cout << "So truoc khi doi: 0x" << std::hex << data << std::endl;
	data = ((data << 8) & 0xff00) | ((data >> 8) & 0x00ff);
	std::cout << "So sau khi doi: 0x" << std::hex << data << std::endl;   //in ra 0x3412
	data = ((data << 4) & 0xfff0) | ((data >> 4) & 0x0f0f);
	std::cout << "So sau khi doi: 0x" << std::hex << data << std::endl;   //in ra 0x4321
	return 0;
}