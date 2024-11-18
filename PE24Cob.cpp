#include <avz.h>
extern AIceFiller aIceFiller;
void AScript()
{
    // ASetReloadMode(AReloadMode::NONE);
    ASetReloadMode(AReloadMode::MAIN_UI_OR_FIGHT_UI);
    ASetZombies({APJ_0, ACG_3, AWW_8, ABC_12, AHT_14, AXC_15, AKG_17, ATT_18, ABY_23, AHY_32, AQQ_16, ABJ_20});
    ASelectCards({AICE_SHROOM, ASUN_SHROOM, ACOFFEE_BEAN, ASCAREDY_SHROOM, AUMBRELLA_LEAF, AM_ICE_SHROOM, ASQUASH, ALILY_PAD, APUFF_SHROOM, ATALL_NUT});
    // PSD PD ICE2
    AConnect(ATime(1, -599), [] {
        aCobManager.AutoGetList();
    });
    AConnect(ATime(1, -599), [] {
        aIceFiller.Start({{4, 9}});
    });
    for (auto wave : {1, 4, 7, 11, 14, 17}) {
        // PD
        AConnect(ATime(wave, -14), [] {
            aCobManager.Fire({{2, 9}, {5, 9}});
        });
        AConnect(ATime(wave, -14 + 107), [] {
            aCobManager.Fire({{1, 7.7}, {5, 7.7}});
        });
    }
    for (auto wave : {2, 5, 8, 12, 15, 18}) {
        // ICE2
        AConnect(ATime(wave, -95), [] {
            aCobManager.Fire({{2, 9}, {5, 9}});
        });
        AConnect(ATime(wave, -95 + 373 - 100 - 198), [] {
            aIceFiller.Coffee();
        });
    }
    for (auto wave : {3, 6, 9, 10, 13, 16, 19}) {
        // PSD
        AConnect(ATime(wave, -95), [] {
            aCobManager.Fire({{2, 9}, {5, 9}, {2, 9}, {5, 9}});
        });
        AConnect(ATime(wave, -95 + 110), [] {
            aCobManager.Fire({{1, 9}, {5, 9}});
        });
    }
    AConnect(ATime(19, -95 + 111), [] {
        aCobManager.RecoverFire({{2, 9}, {5, 9}});
    });
    AConnect(ATime(10, 100), [] { ACard(AUMBRELLA_LEAF, 5, 9); });
    AConnect(ATime(9, -95 + 111), [] {
        aCobManager.RecoverFire({{2, 9}, {5, 9}});
    });
    // w20 PSD
    AConnect(ATime(20, 100), [] { ACard(AUMBRELLA_LEAF, 5, 9); });
    AConnect(ATime(20, -95), [] {
        aCobManager.Fire({{2, 9}, {5, 9}, {2, 9}, {5, 9}});
    });
    AConnect(ATime(20, -95 + 110), [] {
        aCobManager.Fire({{1, 9}, {5, 9}});
    });
    AConnect(ATime(20, -95 + 111), [] {
        aCobManager.RecoverFire({{{2, 9}}});
    });
    AConnect(ATime(20, -95 + 111 + 400), [] {
        aCobManager.RecoverFire({{{2, 9}, {5, 9}}});
    });
    AConnect(ATime(20, -150), [] {
        aCobManager.Fire(4, 7);
    });
}