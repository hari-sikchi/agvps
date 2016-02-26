#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>

using namespace cv;
using namespace std;

struct point_{ int x; int y; };
typedef struct point_ point;

Mat draw(Mat img,int **visited,int **sdist,int s1,int s2,int e1,int e2)
{
for(int i=-1;i<=1;i++)
{
for(int j=-1;j<=1;j++)
{
if (sdist[e1-i][e2-j]==sdist[e1][e2]-1)
{
img.at<Vec3b>(e1-i,e2-j)[0]=255;
img.at<Vec3b>(e1-i,e2-j)[1]=0;
img.at<Vec3b>(e1-i,e2-j)[2]=0;
e1=e1-i;e2=e2-j;
if(e1==s1&&e2==s2)
{
return img;
}
else
draw(img,visited,sdist, s1, s2,e1, e2);

}
}
}
}
void bfs(Mat img,int **visited,int **sdist,int s1,int s2,int e1,int e2)
{
	
	cout << i << " " << j << "   ";
	queue<point> s;
	int k, l;
for(int i=0;i<img.rows;i++)
{
for(int j=0;j<img.cols;j++)
{
visited[i][j]=0;
}
}

for(int i=0;i<img.rows;i++)
{
for(int j=0;j<img.cols;j++)
{

sdist[i][j]=999999;
}
}
sdist[s1][s2]=0;

	point start = { s1, s2 };
point end={e1,e2};
	point current;
	s.push(start);
        
	while (!s.empty())
	{
		//pop top most element from stack and mark as visited
		current = s.front();
		s.pop();
		visited[current.x][current.y] = 1;
if (visited[current.x-1][current.y-1]==0&&(img.at<Vec3b>(current.x-1,current.y-1)[0]!=255&&img.at<Vec3b>(current.x-1,current.y-1)[1]!=255&&img.at<Vec3b>(current.x-1,current.y-1)[2]!=255))
visited[current.x-1][current.y-1] = 1;
s.push({current.x-1,current.y-1});
sdist[current.x-1][current.y-1]=sdist[current.x][current.y]+1;
if (visited[current.x][current.y-1]==0&&(img.at<Vec3b>(current.x,current.y-1)[0]!=255&&img.at<Vec3b>(current.x,current.y-1)[1]!=255&&img.at<Vec3b>(current.x,current.y-1)[2]!=255))
s.push({current.x,current.y-1});
visited[current.x][current.y-1] = 1;
sdist[current.x][current.y-1]=sdist[current.x][current.y]+1;
if (visited[current.x+1][current.y-1]==0&&(img.at<Vec3b>(current.x+1,current.y-1)[0]!=255&&img.at<Vec3b>(current.x+1,current.y-1)[1]!=255&&img.at<Vec3b>(current.x+1,current.y-1)[2]!=255))
s.push({current.x+1,current.y-1});
visited[current.x+1][current.y-1] = 1;
sdist[current.x+1][current.y-1]=sdist[current.x][current.y]+1;
if (visited[current.x-1][current.y]==0&&(img.at<Vec3b>(current.x-1,current.y)[0]!=255&&img.at<Vec3b>(current.x-1,current.y)[1]!=255&&img.at<Vec3b>(current.x-1,current.y)[2]!=255))
visited[current.x-1][current.y] = 1;
s.push({current.x-1,current.y});
sdist[current.x-1][current.y]=sdist[current.x][current.y]+1;
if (visited[current.x+1][current.y]==0&&(img.at<Vec3b>(current.x+1,current.y)[0]!=255&&img.at<Vec3b>(current.x+1,current.y)[1]!=255&&img.at<Vec3b>(current.x+1,current.y)[2]!=255))
visited[current.x+1][current.y] = 1;
s.push({current.x+1,current.y});
sdist[current.x+1][current.y]=sdist[current.x][current.y]+1;
if (visited[current.x-1][current.y+1]==0&&(img.at<Vec3b>(current.x-1,current.y+1)[0]!=255&&img.at<Vec3b>(current.x-1,current.y+1)[1]!=255&&img.at<Vec3b>(current.x-1,current.y+1)[2]!=255))
visited[current.x-1][current.y+1] = 1;
s.push({current.x-1,current.y+1});
sdist[current.x-1][current.y+1]=sdist[current.x][current.y]+1;
if (visited[current.x][current.y+1]==0&&(img.at<Vec3b>(current.x,current.y+1)[0]!=255&&img.at<Vec3b>(current.x,current.y+1)[1]!=255&&img.at<Vec3b>(current.x,current.y+1)[2]!=255))
visited[current.x][current.y+1] = 1;
s.push({current.x,current.y+1});
sdist[current.x][current.y+1]=sdist[current.x][current.y]+1;
if (visited[current.x+1][current.y+1]==0&&(img.at<Vec3b>(current.x+1,current.y+1)[0]!=255&&img.at<Vec3b>(current.x+1,current.y+1)[1]!=255&&img.at<Vec3b>(current.x+1,current.y+1)[2]!=255))
visited[current.x+1][current.y+1] = 1;
s.push({current.x+1,current.y+1});
sdist[current.x+1][current.y+1]=sdist[current.x][current.y]+1;

if(visited[end.x][end.y] = 1;)
{
Mat drawn=draw(img,visited,sdist,s1,s2,e1,e2);
break;
}

	}
	
imshow("sdist",drawn);

}

int main(int argc, char** argv)
{
Mat img = imread("/home/harshit/Downloads/ps1.jpg", CV_LOAD_IMAGE_GRAYSCALE);//change it to binary
int s1=0,s2=0,e1=img.rows,e2=img.cols;
int **visited = new int*[img.rows];
	for (i = 0; i < img.rows; i++)
	{
		visited[i] = new int[img.cols];
	}
int **sdist = new int*[img.rows];
	for (i = 0; i < img.rows; i++)
	{
		sdist[i] = new int[img.cols];
	}
bfs(img,visited,sdist,s1,s2,e1,e2);
}
