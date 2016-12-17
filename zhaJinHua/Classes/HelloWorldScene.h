#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer
{

public:
	CCMenuItemImage *pCloseItem;
	CCMenuItemImage *ready;
	CCMenuItemImage *genzhu;
	CCMenuItemImage *bipai;
	CCMenuItemImage *kanpai;
	CCMenuItemImage *fangqi;
	CCMenu* ready1;
	void ongenzhu(CCObject* pSender);
	void onready(CCObject* pSender);
	CCSprite* q[5];
	CCSprite* tu[50];
	int l1;
	 CCSprite* ying;
	 CCSprite* shu;
	 CCSprite* pSprite;
	 CCSprite* pSprite1;
	 CCSprite* pSprite2;
	 CCMenuItemImage* pSprite3;
	 CCSprite* pSprite4;
	 CCSprite* poker[6];
	 CCSprite* pai1[3];
	 CCSprite* pai2[3];
	 CCMenuItemImage *look;
	 CCSprite* coin;
	 CCSprite* menu;
	 int cart[52];
	 int uscart[3];
	 int comcart[3];
	 CCLabelTTF* money1;
	 int playerGold;
	 CCSprite* money;
	 int a[3];
	 int b[3];
	 int flag[52];
	 CCSize size;
	 int wo;
	 int ta;
	 int jiang;
	 
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void ok(CCObject* pSender);
	void shuffle();
	void getPoker();
	void awardGold(int gold);
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	void paint();
	CCSprite* qq(int i);
	CCSprite* getPhoto(int i);
	void compare();
	int leopard(int a[3]);
	int sequence(int a[3]);
	int staight(int a[3]);
	int samecolor(int a[3]);
	int brother(int a[3]);
	int HighCard(int a[3]);

	int getScore(int a[3]);
	void win();
	void lose();
	void recompare();
	void kan(CCObject* pSender);
	void onbipai(CCObject* pSender);
	void onkanpai(CCObject* pSender);
	void onfangqi(CCObject* pSender);
	void lookmine();
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__