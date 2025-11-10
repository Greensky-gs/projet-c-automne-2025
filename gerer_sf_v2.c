#include <stdio.h>
#include "fourni/V2/bloc.h"
#include "fourni/V2/inode.h"
#include "fourni/V2/sf.h"

int main() {
    tSF syst = CreerSF("ssd");

    AfficherSF(syst);

    Ecrire1BlocFichierSF(syst, "test.txt", ORDINAIRE);

    AfficherSF(syst);

    DetruireSF(&syst);

    return 0;
}