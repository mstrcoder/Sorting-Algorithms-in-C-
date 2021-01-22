#include<graphics.h>
#include<bits/stdc++.h>
#define RED COLOR(0, 255, 0)
#define GREEN COLOR(255, 0, 0)
using namespace std;
void generateArray(vector<int> &numbers, int size, int gap){
	for(int i=1;i<=size;i++){
                numbers.push_back(i);
        }
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(numbers.begin(), numbers.end(), default_random_engine(seed));
	for(int i=1;i<=gap*size;i+=gap){
                if(numbers[i/gap] <= size/2){
                    setcolor(RED);
                }
                else{
                    setcolor(GREEN);
                }
                line(i, size, i, (size - numbers[i / gap]));
        }
}
void interchange(int i, int j, int x, int y, int size, int gap){
	setcolor(GREEN);
	line(i, size, i, size-x);
	delay(0.5);
	setcolor(BLACK);
	line(i, size, i, size-x);
	delay(0.5);
	setcolor(WHITE);
	line(i, size, i, size-y);
	delay(0.5);

	setcolor(GREEN);
    line(j, size, j, size-y);
    delay(0.5);
	setcolor(BLACK);
	line(j, size, j, size-y);
    delay(0.5);
	setcolor(WHITE);
    line(j, size, j, size-x);
	delay(0.5);
}
void interchange(int i, int x, int y, int size, int gap){
	setcolor(GREEN);
	line(i, size, i, size-x);
	delay(1);
	setcolor(BLACK);
	line(i, size, i, size-x);
	delay(1);
	if(y <= size/2){
        setcolor(RED);
        line(i, size, i, size-y);
        delay(1);
	}
	else{
        setcolor(GREEN);
        line(i, size, i, size-y);
        delay(1);
	}

}
void bubbleSort(vector<int> &numbers, int size, int gap){
	for(int i=1;i<size;i++){
		for(int j=0;j<size-i;j++){
			if(numbers[j] > numbers[j+1]){
				swap(numbers[j], numbers[j+1]);
				interchange(gap * j + 1, gap * (j+1) + 1, numbers[j+1], numbers[j], size, gap);
			}
		}
	}
}
void merge(vector<int> &numbers, int size, int gap, int left, int mid, int right){
	vector<int> leftnumbers(mid-left+1), rightnumbers(right-mid);
	for(int i=0;i<leftnumbers.size();i++){
		leftnumbers[i] = numbers[left+i];
	}
	for(int i=0;i<rightnumbers.size();i++){
		rightnumbers[i] = numbers[mid+1+i];
	}
	int i=0, j=0, k=left;
	while(i < leftnumbers.size() && j < rightnumbers.size()){
		if(leftnumbers[i] <= rightnumbers[j]){
			interchange(gap*k + 1, numbers[k], leftnumbers[i], size, gap);
			numbers[k] = leftnumbers[i];
			i++;
		}
		else{
			interchange(gap*k + 1, numbers[k], rightnumbers[j], size, gap);
			numbers[k] = rightnumbers[j];
			j++;
		}
		k++;
	}
	while(i < leftnumbers.size()){
		interchange(gap*k + 1, numbers[k], leftnumbers[i], size, gap);
		numbers[k] = leftnumbers[i];
		i++;
		k++;
	}
	while(j < rightnumbers.size()){
		interchange(gap*k + 1, numbers[k], rightnumbers[j], size, gap);
		numbers[k] = rightnumbers[j];
		j++;
		k++;
	}
}
void mergeSort(vector<int> &numbers, int size, int gap, int left, int right){
	if(left < right){
		int mid = (left + right)/2;
		mergeSort(numbers, size, gap, left, mid);
		mergeSort(numbers, size, gap, mid+1, right);
		merge(numbers, size, gap, left, mid, right);
	}
}


int main(){
	int gd = DETECT, gm;
	vector<int> numbers;
	initgraph(&gd, &gm, "");
	int size = 750, gap = 2;
    int wid1;
    wid1 = initwindow(gap * size + 1, size + 1);
    setcurrentwindow(wid1);

	generateArray(numbers, size, gap);

	delay(1000);
	//bubbleSort(numbers, size, gap);
	mergeSort(numbers, size, gap, 0, numbers.size()-1);
	/*for(int i=0;i<numbers.size();i++){
        cout << numbers[i] << " ";
	}
	*/
	getch();
	closegraph();
	return 0;
}
