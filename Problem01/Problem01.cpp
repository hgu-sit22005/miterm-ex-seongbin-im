#include <iostream>
#include <random>
#include <ctime>

char* generate_3_digit()
{
	char *res = new char[10];
	for(int i=0 ; i<10; i++)
		res[i] = i+'0'; //i는 int이기 때문에 ASCII코드로 바꿔주기 위해 뒤에 '0'붙힌것 '0' 붙히면 앞에 int가 ASCII로 바뀜

	for(int i=0;i<3;i++){
		char buf;
		int index=rand()%(10-i);
		buf=res[index];
		res[i]=res[index];
		res[index] = buf;
	}
	return 0;

}

int main()
{
	// Game initalization
	char guess[3];
	int trials = 0;

	char* answer = generate_3_digit();
		
	int strike = 0, ball = 0, out = 0;
	while(strike != 3)
	{
		trials++;

		strike = 0;
		ball = 0;
		out = 0;

		std::cout << "Guess three number: (ex. 1 2 3)" << std::endl;
		std::cin >> guess[0] >> guess[1] >> guess[2];

		for(int i=0;i<3;i++){
			if(answer[i]==guess[i]){
				strike++;
				continue;
			}
			else{
				bool bFlag = false;
				for(int j=0;j<3;j++){
					if(answer[j]==guess[i]){
						ball++;
						bFlag=true;
						break;
					}
				}
				if(bFlag != true)
					out++;
			}
		}
		
	






















	
		std::cout << "S:" << strike << " B:" << ball << " O:"<< out << std::endl;
	}
	
	std::cout << "You have found the right number with " << trials << " trials" << std::endl;

	delete[] answer;
	return 0;
}