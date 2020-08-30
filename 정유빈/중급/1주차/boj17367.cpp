#include <iostream>
#include <cmath>



using namespace std;

//규칙
// 주사위 3개 던지기
// 눈 3개같 만원+눈*1000원 	6가지		
// 눈2개같 천원+같은 눈*100원	90가지
// 다른눈 큰눈*100원 			120가지

//구하는것 = N이 주어졌을 때 기댓값
//시행 = N <= 1000
// 3 <= 던지는 횟수 <= N

//분석
//뭐가 어떻든 마지막 세번의 주사위.
//aaa 나오면 스탑				이거랑
//abb 나오면 무조건 굴리는게 이득.		이거	
//aba aab 나오면 뭐가 이득일지는 모름. -> 계산해보니까 시행 3회 이상 남아있지 않는 한 스탑		이게 아닌듯
//abc 무조건 굴림

//위에꺼 쓰지 말고
//그냥 디피 하자...

int N;
double cache[7][7][7][1001];

int getMoney(int a, int b, int c)
{
	if(a==b && a==c)
		return 10000+a*1000;
	else if(a==b || a==c)
		return 1000+a*100;
	else if(b==c)
		return 1000+b*100;
	else
		return max(max(a,b),c)*100;
	
}




double dp(int a, int b, int c, int depth) {		
	double e = 0;
	if(cache[a][b][c][depth] != -1)			//이미 계산한 적이 있으면 그걸 반환(memoization)
		return cache[a][b][c][depth];
	
	if(depth >= N)
		return getMoney(a,b,c)/216.0; 		//기저

	//그냥 현재 형태 상관 하지 말것
	// if((a == b && b == c) || (depth > 3 && N-depth <= 2 && (a==b || a==c)))	//aaa 이거나 1회 시행을 남겨두고 aab, aba일 경우 
	// 	return getMoney(a,b,c)/216.0;
	
	
	
	for(int i = 1; i<=6; i++)				//다음 시행 : e
		e += dp(b,c,i, depth+1)/6.0;
	
	return cache[a][b][c][depth] = max(e, getMoney(a,b,c)/216.0);
}

double dp() {	//진입
	double sum = 0;
	for(int i = 1; i<=6; i++)
		for(int j = 1; j<=6; j++)
			for(int k = 1; k<=6; k++)
				sum += dp(i,j,k,3);
	return sum;
}


int main()
{
	fill(&cache[0][0][0][0], &cache[6][6][6][1000]+1, -1.0);	//cache 초기화
	cin >> N;
	cout.precision(12);
	cout << fixed << dp() << endl;
}



//확률에 그리디도 안먹히고 직접 식계산하니까 머리터지고 죽을것같음
//aaa,aba 이런식으로 나눈게 독이 된 듯
//교훈 : O(2^n)	 꼴에서는 그냥 적당히 그리디 넣을 생각 하지 말고 dp만 넣자
