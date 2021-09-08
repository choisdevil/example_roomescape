/*
개발자 : 홍길동, 강감찬, 이순신
개발일 : 2021.09.08.
문의 : abcde@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

void intro();
void room();
void frame();	//1. 액자
void bed();		//2. 침대
void fridge();	//3. 냉장고
void safebox();	//4. 금고
void closet();	//5. 옷장
void door();	//6. 출입문
void door_password();

int isBrokenFrame = FALSE;	//액자 파손여부
int isBrokenBed = FALSE;	//침대 파손여부

int isFindMagnifyingGlass = FALSE;	//돋보기 습득여부
int isFindGoldKey = FALSE;		//금색 열쇠 획득 여부
int isFindSilverKey = FALSE; 	//은색 열쇠 획득 여부

int isOpenSafebox = FALSE;		//금고 오픈 여부

int main() {
	int menu;

	while(1) {
		printf("ROOM ESCAPE VER 1.0\n\n");
		printf("1. 입장\n");
		printf("0. 종료\n");
		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				intro();
				room();
				break;
			case 0:
				return 0;
			default:
				printf("입력 오류\n\n");
				break;
		}
	}

}

void intro() {
	system("cls");
	printf("\n\n");
	printf("눈을 떠보니 작은 방 안에 있는 것 같다.\n");
	Sleep(1500);
	printf("여긴 어디지... 어젯밤 기억이 잘 나지 않는다.\n\n");
	Sleep(2500);
	printf("옷장, 침대, 냉장고.. 모든 물건이 낯설다.\n");
	Sleep(1500);
	printf("대체 누가 날 여기에 데리고 온 것일까?\n\n");
	Sleep(2500);
	printf("하지만 지금은 그런 걸 따질 시간이 없다.\n");
	Sleep(1500);
	printf("이 방을 나가야 한다.\n\n");
	Sleep(1500);
	system("pause");
}

void room() {
	int menu;

	while(1) {
		system("cls");
		printf("[원룸]\n\n");
		printf("방 안에서 할 수 있는 것들을 찾아보자.\n\n");
		printf("1. 액자    2. 침대    3. 냉장고\n");
		printf("4. 금고    5. 옷장    6. 출입문\n");

		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				if(isBrokenFrame) {
					printf("\n액자를 부서버렸다. 더 이상 찾을 수 없다.\n");
					system("pause");
				} else {
					frame();
				}
				break;
			case 2:
				bed();
				break;
			case 3:
				fridge();
				break;
			case 4:
				safebox();
				break;
			case 5:
				closet();
				break;
			case 6:
				door();
				break;
			default:
				printf("\n# ERROR # 입력값 오류\n");
				system("pause");
		}
	}

}

void frame(){//1. 액자
	int menu;

	while(1) {
		system("cls");
		printf("[원룸]-[액자]\n\n");
		printf("벽에 큰 액자가 걸려있다.\n\n");
		printf("1. 액자를 살펴본다\n");
		printf("2. 액자를 부순다\n");
		printf("0. 돌아가기\n");

		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				if(isFindMagnifyingGlass) {
					printf("\n액자 상단에 은하철도라고 써있는 것 같다.\n");
					printf("뒤에 숫자가 써 있는것 같은데.. 잘 보이지 않는다.\n\n");
				} else {
					printf("\n액자에서 특이한 점이 보이지 않는다.\n\n");
				}
				break;
			case 2:
				isBrokenFrame = TRUE;
				printf("\n액자를 부서버렸다.\n");
				printf("짜증나는구만!\n\n");
				system("pause");
				return;
			case 0:
				return;
			default:
				printf("\n# ERROR # 입력값 오류\n\n");
				break;
		}
		system("pause");
	}
}

void bed() {//2. 침대
	int menu;

	while(1) {
		system("cls");
		printf("[원룸]-[침대]\n\n");
		printf("방 한 구석에 1인용 침대가 설치되어 있다.\n\n");
		printf("1. 침대 밑을 살펴본다\n");
		printf("2. 침대를 살펴본다\n");
		printf("3. 베개를 살펴본다\n");
		printf("0. 돌아가기\n");

		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				if(isBrokenBed)  {
					printf("\n침대가 부서져서 더 이상 찾을 수 없다.\n\n");
				} else {
					printf("\n어두워서 아무것도 보이지 않는다.\n");
					printf("손전등이라도 있으면 좋을텐데..\n\n");
				}
				system("pause");
				break;
			case 2:
				if(isBrokenBed) {
					printf("\n침대가 부서져서 더 이상 찾을 수 없다.\n\n");
				} else {
					system("cls");
					printf("[원룸]-[침대]-[침대]\n\n");
					printf("\n누가 누워있던 흔적 말고는 딱히 이상한 점이 보이지 않는다.\n\n");
					printf("1. 침대를 부순다.\n");
					printf("2. 침대를 가만히 둔다.\n");
					printf(">> ");
					scanf("%d", &menu);

					switch(menu) {
						case 1:
							isBrokenBed = TRUE;	//침대 부서짐
							printf("\n# 침대가 산산조각 나버렸다. # \n\n");
							printf("1. 잔해를 뒤진다.\n");
							printf("2. 가만히 둔다.\n");
							printf(">> ");
							scanf("%d", &menu);

							switch(menu) {
								case 1:
									printf("\n찢어진 설계도면이 있다. 침대 제작 도면인가?\n");
									printf("도면 상단에 희미하게 숫자가 씌어있다.\n");
									printf("No.53-49-48-54 라고 쓰여있는 것 같다. 제품번호인가?\n\n");
									break;
								case 2:
									printf("\n치우기 귀찮다. 그냥 두자.\n\n");
									break;
							default:
								printf("\n결정을 못했다. 돌아가자.\n\n");
								break;
							}
							break;
						case 2:
							printf("\n내가 누워야 하니까 내비두자..\n\n");
							break;
						default:
							printf("\n결정을 못했다. 돌아가자.\n\n");
							break;
					}
				}
				system("pause");
				break;
			case 3:
				system("cls");
				printf("[원룸]-[침대]-[베개]\n\n");
				printf("\n베개에서는 특이한 점이 보이지 않는다.\n\n");
				printf("1. 베개 속을 뒤진다\n");
				printf("2. 베개를 가만히 둔다\n");
				printf(">> ");
				scanf("%d", &menu);

				switch(menu) {
					case 1:
						if(isFindGoldKey) {
							printf("\n열쇠는 아까 찾았다. 다른 것은 보이지 않는다.\n\n");
						} else {
							isFindGoldKey = TRUE;	//금색 열쇠 획득
							printf("\n베개 속에서 금색 열쇠를 찾았다. 중요한 단서인가?\n\n");
						}
						break;
					case 2:
						printf("\n내가 누워야 하니까 내비두자..\n\n");
						break;
					default:
						printf("\n결정을 못했다. 돌아가자.\n\n");
						break;

				}
				system("pause");
				break;
			case 0:
				return;
			default:
				printf("# ERROR # 입력값 오류\n\n");
				system("pause");
		}
	}
}

void fridge(){//3. 냉장고
	int menu;

	while(1) {
		system("cls");
		printf("[원룸]-[냉장고]\n\n");
		printf("딱 봐도 낡아보이는 냉장고 하나가 있다.\n");
		printf("냉장고 안에는 여러 식품이 있다.\n\n");
		printf("1. 우유를 살펴본다\n");
		printf("2. 스파게티를 살펴본다\n");
		printf("3. 김치를 살펴본다\n");
		printf("4. 콜라를 살펴본다\n");
		printf("5. 스팸을 살펴본다\n");
		printf("0. 돌아가기\n");

		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				printf("\n유통기한이 2020년? 날짜가 한참 지났다.\n");
				printf("\n이걸 먹으면 식중독에 걸리겠지?\n\n");
				break;
			case 2:
				printf("\n냄새가 좋지 않다. 상한 것 같은데..\n\n");
				break;
			case 3:
				printf("\n냉장고가 오래되서 그런가? 김치가 다 쉬었다.\n\n");
				break;
			case 4:
				printf("\n탄산이 다 빠져있다. 콜라는 탄산이 생명인데..\n\n");
				break;
			case 5:
				printf("\n역시 햄은 스팸이지!\n\n");
				break;
			case 0:
				return;
			default:
				printf("\n# ERROR # 입력값 오류\n\n");
				break;
		}
		system("pause");
	}
}

void safebox(){//4. 금고
	int menu;

	while(1) {
		system("cls");
		printf("[원룸]-[금고]\n\n");
		printf("엄청 단단해보이는 금고다.\n\n");
		printf("1. 금고를 연다\n");
		printf("2. 금고를 부순다\n");
		printf("3. 금고를 살펴본다\n");
		printf("0. 돌아가기\n");

		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				if(isOpenSafebox) {
					printf("\n금고는 이미 열어서 아무것도 없다.\n\n");
					break;
				}
				if(isFindGoldKey && isFindSilverKey) {
					isFindMagnifyingGlass = TRUE;	//돋보기 습득
					isOpenSafebox = TRUE;	//금고 열었음
					printf("\n금고 안에서 메모지와 돋보기를 찾았다.\n");
					printf("메모지에는 작은 글씨로 글이 적혀있다.\n\n");
					printf("'멈춘다는 것은 냄비와 같고, 살아있다는 것은 악마와도 같다.\n");
					printf("그물이랑 같은 것은 무엇일까..'\n\n");
					printf("무슨 뜻이지...?\n\n");
				} else {
					printf("\n금고를 열기 위해 필요한 열쇠를 아직 얻지 못한 것 같다.\n\n");
				}
				break;
			case 2:
				printf("\n연장도 없는데 금고를 부순다고? 말도 안돼.\n\n");
				break;
			case 3:
				printf("\n금고에 열쇠 구멍이 두 개가 있다. 특이하군..\n\n");
				break;
			case 0:
				return;
			default:
				printf("\n# ERROR # 입력값 오류\n\n");
				break;
		}
		system("pause");
	}
}

void closet(){//5. 옷장
	int menu;

	while(1) {
		system("cls");
		printf("[원룸]-[옷장]\n\n");
		printf("방 한쪽을 가득 채울 정도의 큰 옷장이다.\n\n");
		printf("1. 정장을 살펴본다\n");
		printf("2. 청바지를 살펴본다\n");
		printf("3. 노란색 티를 살펴본다\n");
		printf("4. 반바지를 살펴본다\n");
		printf("5. 옷장을 부순다\n");
		printf("0. 돌아가기\n");

		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				if(isFindSilverKey) {
					printf("\n정장에서는 더 이상 찾을 것이 없다.\n\n");
				} else {
					isFindSilverKey = TRUE;		//은색 열쇠 찾음
					printf("\n정장 안쪽 주머니에서 은색 열쇠를 찾았다.\n\n");
				}
				break;
			case 2:
				printf("\n아무 것도 찾을 수 없다.\n\n");
				break;
			case 3:
				printf("\nCYBERPUNK 라고 쓰여져 있다. 뒤에 숫자는 지워져서 보이지 않는다.\n\n");
				break;
			case 4:
				printf("\n아무 것도 찾을 수 없다.\n\n");
				break;
			case 5:
				printf("\n옷장이 너무 커서 도끼가 없으면 부수지 못할 것 같다.\n\n");
				break;
			case 0:
				return;
			default:
				printf("\n# ERROR # 입력값 오류\n\n");
				break;
		}
		system("pause");
	}
}

void door(){//6. 출입문
	int menu;

	while(1) {
		system("cls");
		printf("[원룸]-[출입문]\n\n");
		printf("이 방을 나갈 수 있는 유일한 문인 것 같다.\n");
		printf("문 앞에는 종이에 어떤 글귀도 적혀있다.\n\n");

		printf("1. 종이를 살펴본다\n");
		printf("2. 비밀번호를 입력한다\n");
		printf("0. 돌아가기\n");

		printf(">> ");
		scanf("%d", &menu);

		switch(menu) {
			case 1:
				printf("\n종이에는 퀴즈 같은 것이 적혀있다. 일기인가?\n\n");
				printf("'CYBERPUNK를 사고 싶었는데 돈이 모자라서 살 수가 없었다.\n");
				printf("그래서 고기라도 잡아 돈을 벌기 위해 근처 바다에서 그물을 쳤는데 그마저도 많이 잡히지 않는다.\n");
				printf("요즘 고기도 많이 잡히지 않고, 점점 굶는 날이 많아진다.\n");
				printf("오늘은 잡힌 고기를 팔아 겨우 우유 하나를 사왔는데.. 유통기한이 한참 지나버렸다.\n");
				printf("유통기한을 보지 못한 내 잘못이지만 사기당한 느낌이 든다.\n");
				printf("난 왜이렇게 운이 없는 걸까..?\n");
				printf("그녀가 가장 좋아하던 만화를 다시 보면서 숫자 퍼즐을 만들어야겠다.'\n\n");
				break;
			case 2:
				door_password();
				break;
			case 0:
				return;
			default:
				printf("\n# ERROR # 입력값 오류\n\n");
				break;
		}
		system("pause");
	}
}

void door_password() {
	char pass[5] = "5106", temp[5];

	system("cls");
	printf("\n\n      [ PASSWORD ]\n\n");
	printf(">> ");
	scanf("%s", &temp);

	if(!strcmp(pass, temp)) {
		system("cls");
		printf("\n\n드디어 지긋지긋했던 방을 나오게 되었다.\n\n");
		printf("온통 새까만 어둠 속에서 어디로 가야 할 지 모르겠다.\n");
		printf("어떤 사람이 나를 가뒀는지 모르겠지만..\n");
		printf("절대 가만두지 않겠다.\n\n");
		printf("# THE END #\n\n");
		system("pause");
		exit(0);
	} else {
		printf("\n\n# ERROR # PASSWORD FAIL\n\n");
		return;
	}
}

