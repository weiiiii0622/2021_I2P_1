#include <stdio.h>

int main(){

    int  P_HP, P_ATK, P_DEF, E_HP, E_ATK, E_DEF;
    scanf("%d %d %d", &P_HP, &P_ATK, &P_DEF);
    scanf("%d %d %d", &E_HP, &E_ATK, &E_DEF);

    printf("Battle Start \\^_^/\n");

    while(P_HP>0 && E_HP>0){

        int P_DMG = P_ATK - E_DEF;
        int E_DMG = E_ATK - P_DEF;
        printf("The player dealt %d damage to the enemy and the enemy dealt %d damage to the player\n", P_DMG, E_DMG);
        
        P_HP -= E_DMG;
        E_HP -= P_DMG;
        printf("The player has %d HP left and the enemy has %d HP left\n", P_HP, E_HP);
    }

    printf("Battle End \\^_^/\n");

    return 0;
}