struct sockets{
	int schedulerSocket, workerSocket;
	int priority, active;
};

sockets *s;

void add(struct sockets s1){
	//extract connection info from s1
	int socketfd = Create();
	s1.schedulerSocket = socketfd;
	s1.active = 1;
	if(s[0]==NULL)
		s[0] = s1;
	else
		s[sizeof(s)/sizeof(s[0]) = s1;
}

void process(int sockfd){
	char buff[7];

	//recieves the panning speed
	Receive(sockfd, buff, sizeof(int) + 1);
	int panningSpeed = atoi(buff);
	int i;

	//goes through the sockets array and adds/updates the priority.
	//If the panning speed sent was -1 sets the socket entry to inactive
	int len = s[sizeof(s)/sizeof(s[0]);
	for(i=0; i<len; i++){
		if(s[i].schedulerSocket == sockfd){
			if(panningSpeed == -1)
				s[i].active = 0;
			else
				s[i].priority = 1/(panningSpeed+1);
		}
	}
}
