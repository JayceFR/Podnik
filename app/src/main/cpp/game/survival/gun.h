#ifndef GUN_H
#define GUN_H

#ifdef __cplusplus
extern "C" {
#endif

// Each gun should have 
// cooldown -> between bullets 
// ammo 
// reload time -> between magazines 
typedef struct{
    float cooldown; 
    int maxAmmo; 
    float reloadTime; 
    Texture2D texture;

    // projectile
    int numberOfProjectiles;
    float damage; 
    float speed; 
} Gun;

#ifdef __cplusplus
}
#endif


#endif