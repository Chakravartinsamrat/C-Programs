#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Particle{
	float x,y; //position
	float vx,vy; //velocity
};
void updateParticle(struct Particle*particle){
	particle->x+=particle->vx;
	particle->y+=particle->vy;
}
void printParticle(struct Particle*particle){
	printf("Position:(%.2f,%.2f)\n",particle->x,particle->y);
	printf("Velocity:(%.2f,%.2f)\n\n",particle->vx,particle->vy);
}
int main(){
	srand(time(NULL));
	struct Particle particles[4];
	for(int i=0;i<3;i++){
		particles[i].x=(float)(rand() %100)/10.0;
		particles[i].y=(float)(rand() %100)/10.0;
		particles[i].vx=(float)(rand() %21-10)/10.0;
		particles[i].vy=(float)(rand() %21-10)/10.0;
	}
	for(int i=0;i<3;i++)
	{
		printf("Particle %d:\n",i+1);
		printParticle(&particles[i]);
		for(int step=1;step<=5;step++){
			updateParticle(&particles[i]);
			printf("after step %d:\n",step);
			printParticle(&particles[i]);
		}
	}
	return 0;
}