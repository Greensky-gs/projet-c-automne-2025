#include "fourni/V4/repertoire.h"
#include <stdio.h>

#define ADD(x, y) x + y

int main() {
// int testAffichage() {
    tRepertoire rep = CreerRepertoire();

    AfficherRepertoire(rep);

    printf("entrees = %d\n", NbEntreesRepertoire(rep));

    EcrireEntreeRepertoire(rep, "abc", 1);
    
    AfficherRepertoire(rep);

    printf("entrees = %d\n", NbEntreesRepertoire(rep));
    
    EcrireEntreeRepertoire(rep, "def.txt", 3);

    AfficherRepertoire(rep);

    printf("entrees = %d\n", NbEntreesRepertoire(rep));

    EcrireEntreeRepertoire(rep, "abc", 3);

    AfficherRepertoire(rep);
    
    printf("entrees = %d\n", NbEntreesRepertoire(rep));
    
    tInode inode = CreerInode(1, REPERTOIRE);

    EcrireRepertoireDansInode(rep, inode);

    FILE * save = fopen("inode-rep.inode.txt", "wb");

    SauvegarderInode(inode, save);

    fclose(save);

    DetruireInode(&inode);
    DetruireRepertoire(&rep);


    // Test de lecture

    FILE * load = fopen("inode-rep.inode.txt", "rb");

    tInode inode2 = CreerInode(-1, REPERTOIRE);
    ChargerInode(&inode2, load);

    tRepertoire rep2 = CreerRepertoire();

    LireRepertoireDepuisInode(&rep2, inode2);

    AfficherRepertoire(rep2);

    DetruireInode(&inode2);
    DetruireRepertoire(&rep2);
    
    return 0;
}