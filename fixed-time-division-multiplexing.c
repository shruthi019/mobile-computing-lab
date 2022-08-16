#include <stdio.h>

int main() {
    int numberOfStations = 5;
    int totalPackets = 0;
    int maxPacketsTransmittedInSlot = 2;
	int packets[5] = {4, 0, 2, 1, 0};
    int currentPacketsTransmitted[5] = {0, 0, 0, 0, 0};
	
	for (int i = 0; i < numberOfStations; i++) {
        totalPackets = packets[i] + totalPackets;
    }
    
	while (totalPackets > 0) {
        for (int i = 0; i < numberOfStations; i++) {
            printf("Time Slot for Station %d\n", i);
            if (currentPacketsTransmitted[i] == packets[i]) {
                printf("No packets remaining to transmit\n");
            } else if (packets[i] - currentPacketsTransmitted[i] < maxPacketsTransmittedInSlot) {
                printf("Time alloted for transmission of packet #%d from station %d\n", currentPacketsTransmitted[i], i);
                printf("Packet #%d transmitted\n", currentPacketsTransmitted[i]);
                currentPacketsTransmitted[i]++;
                totalPackets--;
            } else {
                printf("Time alloted for transmission of packet #%d from station %d\n", currentPacketsTransmitted[i], i);
                printf("Packet #%d transmitted\n", currentPacketsTransmitted[i]);
                printf("Time alloted for transmission of packet #%d from station %d\n", currentPacketsTransmitted[i] + 1, i);
                printf("Packet #%d transmitted\n", currentPacketsTransmitted[i] + 1);
                currentPacketsTransmitted[i] += maxPacketsTransmittedInSlot;
                totalPackets -= maxPacketsTransmittedInSlot;
            }
            printf("\n\n");
        }
	}
	return 0;	
}
