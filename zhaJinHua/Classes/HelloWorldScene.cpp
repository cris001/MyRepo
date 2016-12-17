#include "HelloWorldScene.h"

using namespace cocos2d;
#include "cocos2d.h"
#include "../CocosDenshion/include/SimpleAudioEngine.h"
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
		/* CCLabelTTF* pLabel = CCLabelTTF::create("Zha Jin Hua", "Arial", 38);
		CC_BREAK_IF(! pLabel);*/

        // Get window size and place the label upper. 
         size = CCDirector::sharedDirector()->getWinSize();
        //pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // Add the label to HelloWorld layer as a child layer.
        //this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        pSprite = CCSprite::create("gold_desk.png");
        CC_BREAK_IF(! pSprite);
		
        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);

		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("backgroundMusic.wav");

		ying = CCSprite::create("face100.png");
		ying->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(ying,1);
		ying->setVisible(false);
		shu = CCSprite::create("face109.png");
		shu->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(shu,1);
		shu->setVisible(false);
		
		

		ready = CCMenuItemImage::create(
			"gold_ready0.png",
			"gold_ready0.png"
			,this,
			menu_selector(HelloWorld::onready)
			);
		ready->setScale(0.5);
		ready->setPosition(ccp(size.width/2,size.height/2-100));
		ready1 = CCMenu::create(ready, NULL);
		ready1->setPosition(CCPointZero);
		this->addChild(ready1, 1);
		ready->setVisible(false);
		ready->setEnabled(false);

		pSprite1 = CCSprite::create("1.bmp");
		pSprite1->setPosition(ccp(size.width/2-100,size.height-100));
		this->addChild(pSprite1, 0);

		 pSprite2 = CCSprite::create("10.png");
		pSprite2->setPosition(ccp(size.width/2-100,100));
		this->addChild(pSprite2, 0);

		// pSprite3 = CCSprite::create("gold_room0.png");
		//// pSprite3 =CCSprite::spriteWithFile(s_MenuItem,CCRectMake(0,23*2,115,23));
		//pSprite3->setPosition(ccp(size.width/2+200,300));
		//pSprite3->setScale(0.4);
		//this->addChild(pSprite3, 0);

		pSprite3 = CCMenuItemImage::create(
			"gold_room0.png",
			"gold_room0.png"
			,this,
			menu_selector(HelloWorld::ok)
			);
		pSprite3->setPosition(ccp(size.width/2+200,300));
		pSprite3->setScale(0.4);

		CCMenu* pMenu1 = CCMenu::create(pSprite3, NULL);
		pMenu1->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu1);

		// Add the menu to HelloWorld layer as a child layer.
		this->addChild(pMenu1, 1);

		pSprite4 = CCSprite::create("gold_sendcard.png");
		pSprite4->setPosition(ccp(size.width/2,400));
		//pSprite4->setScale(0.4);
		this->addChild(pSprite4, 0);

		look = CCMenuItemImage::create(
			"gold_peerc2.png",
			"gold_peerc2.png"
			,this,
			menu_selector(HelloWorld::kan)
			);
		look->setPosition(ccp(900,100));
		look->setScale(0.8);

		CCMenu* pMenu2 = CCMenu::create(look, NULL);
		pMenu2->setPosition(CCPointZero);
		this->addChild(pMenu2, 1);
		look->setEnabled(false);

		menu = CCSprite::create("0000.png");
		menu->setPosition(ccp(400,280));
		menu->setScale(0.8);
		this->addChild(menu, 1);

		money1 = CCLabelTTF::create("$1000", "Arial",25);
		money1->setPosition(ccp(200,100));
		this->addChild(money1, 1);

		coin = CCSprite::create("gold_lotterycoin.png");
		coin->setPosition(ccp(200,70));
		coin->setScale(0.8);
		this->addChild(coin, 0);
		playerGold=1000;

		for (int i=0;i<6;i++)
		{
		poker[i]=CCSprite::create("gold_loginCard.png");
		poker[i]->setPosition(ccp(size.width/2,415));
		poker[i]->setScale(0.65);
		this->addChild(poker[i], 0);
		}

		genzhu = CCMenuItemImage::create(
			"genzhu.png",
			"genzhu.png"
			,this,
			menu_selector(HelloWorld::ongenzhu)
			);
		genzhu->setPosition(ccp(263,262));
		genzhu->setScale(0.8);

		CCMenu* gen = CCMenu::create(genzhu, NULL);
		gen->setPosition(CCPointZero);
		this->addChild(gen, 1);

		bipai = CCMenuItemImage::create(
			"bipai.png",
			"bipai.png"
			,this,
			menu_selector(HelloWorld::onbipai)
			);
		bipai->setPosition(ccp(353,262));
		bipai->setScale(0.8);

		CCMenu* bi = CCMenu::create(bipai, NULL);
		bi->setPosition(CCPointZero);
		this->addChild(bi, 1);

		kanpai = CCMenuItemImage::create(
			"kanpai.png",
			"kanpai.png"
			,this,
			menu_selector(HelloWorld::onkanpai)
			);
		kanpai->setPosition(ccp(443,262));
		kanpai->setScale(0.8);

		CCMenu* kan1 = CCMenu::create(kanpai, NULL);
		kan1->setPosition(CCPointZero);
		this->addChild(kan1, 1);

		fangqi = CCMenuItemImage::create(
			"fangqi.png",
			"fangqi.png"
			,this,
			menu_selector(HelloWorld::onfangqi)
			);
		fangqi->setPosition(ccp(533,262));
		fangqi->setScale(0.8);

		CCMenu* fang = CCMenu::create(fangqi, NULL);
		fang->setPosition(CCPointZero);
		this->addChild(fang, 1);


		menu->setVisible(false);
		genzhu->setVisible(false);
		genzhu->setEnabled(false);
		kanpai->setVisible(false);
		kanpai->setEnabled(false);
		bipai->setVisible(false);
		bipai->setEnabled(false);
		fangqi->setVisible(false);
		fangqi->setEnabled(false);

		setTouchEnabled(true);
        bRet = true;
    } while (0);

    return bRet;
}
void HelloWorld::onready(CCObject* pSender)
{
	ying->setVisible(false);
	shu->setVisible(false);
	ready->setVisible(false);
	ready->setEnabled(true);
	pSprite3->setVisible(true);
	pSprite3->setEnabled(true);
	for (int i=0;i<3;i++)
	{
		
		pai1[i]->setVisible(false);
		pai1[i]->setPosition(ccp(0,0));
		//this->removeChild(pai1[i],true);
		//pai1[i]->removeFromParent();
	}
	for (int i=0;i<3;i++)
	{
		this->removeChild(pai2[i],0);
	}
	
}
void HelloWorld::ok(CCObject* pSender)
{
	shuffle();
	//paint();
	jiang=300;
	//setTouchEnabled(false);
	//pSprite3->setOrderOfArrival(0);
	//pCloseItem->setEnabled(false);
	pSprite3->setEnabled(false);
	for (int i=1;i<=6;i++)
	{
		if (i%2==1)
		{
			CCActionInterval* moveto = CCMoveBy::create(0.5f,ccp(i*20,-320));
			poker[i-1]->runAction(moveto);

		} else
		{
			CCActionInterval* moveto1 = CCMoveBy::create(0.5f,ccp(i*15,250));
			poker[i-1]->runAction(moveto1);

		}
		money = CCSprite::create("gold_purchase1.png");
		money->setPosition(ccp(300,400));
		money->setScale(1.5);
		this->addChild(money, 0);
		awardGold(-50);
		look->setEnabled(true);


		menu->setVisible(true);
		genzhu->setVisible(true);
		genzhu->setEnabled(true);
		kanpai->setVisible(true);
		kanpai->setEnabled(true);
		bipai->setVisible(true);
		bipai->setEnabled(true);
		fangqi->setVisible(true);
		fangqi->setEnabled(true);

		l1=1;
		/*genzhu = CCMenuItemImage::create(
			"genzhu.png",
			"genzhu.png"
			,this,
			menu_selector(HelloWorld::ongenzhu)
			);
		genzhu->setPosition(ccp(263,262));
		genzhu->setScale(0.8);

		CCMenu* gen = CCMenu::create(genzhu, NULL);
		gen->setPosition(CCPointZero);
		this->addChild(gen, 1);

		bipai = CCMenuItemImage::create(
			"bipai.png",
			"bipai.png"
			,this,
			menu_selector(HelloWorld::onbipai)
			);
		bipai->setPosition(ccp(353,262));
		bipai->setScale(0.8);

		CCMenu* bi = CCMenu::create(bipai, NULL);
		bi->setPosition(CCPointZero);
		this->addChild(bi, 1);

		kanpai = CCMenuItemImage::create(
			"kanpai.png",
			"kanpai.png"
			,this,
			menu_selector(HelloWorld::onkanpai)
			);
		kanpai->setPosition(ccp(443,262));
		kanpai->setScale(0.8);

		CCMenu* kan1 = CCMenu::create(kanpai, NULL);
		kan1->setPosition(CCPointZero);
		this->addChild(kan1, 1);

		fangqi = CCMenuItemImage::create(
			"fangqi.png",
			"fangqi.png"
			,this,
			menu_selector(HelloWorld::onfangqi)
			);
		fangqi->setPosition(ccp(533,262));
		fangqi->setScale(0.8);

		CCMenu* fang = CCMenu::create(fangqi, NULL);
		fang->setPosition(CCPointZero);
		this->addChild(fang, 1);*/

	}

}
void HelloWorld::ongenzhu(CCObject* pSender)
{
	l1++;
	tu[l1]= CCSprite::create("gold_purchase1.png");
	srand(time(NULL));
	int c;
	c=rand()%60;
	int c1;
	c1=rand()%60;
	tu[l1]->setPosition(ccp(300+c,400+c1));
	tu[l1]->setScale(1.5);
	this->addChild(tu[l1], 0);
	awardGold(-50);
	jiang+=50;
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game_raise_4.mp3");
}
void HelloWorld::onbipai(CCObject* pSender)
{
	paint();
	compare();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game_compare_4.mp3");
}

void HelloWorld::onkanpai(CCObject* pSender)
{
	//shuffle();
	//getPoker(); 
	paint();
	lookmine();
	//compare();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game_check_1.mp3");
}
void HelloWorld::onfangqi(CCObject* pSender)
{
	paint();
	lose();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game_fold_2.mp3");
}


void HelloWorld::kan(CCObject* pSender)
{
	
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}
void HelloWorld::awardGold(int gold)
{
	playerGold += gold;
	money1->setString(CCString::createWithFormat("$%d", playerGold)->getCString());
}


void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(pTouches->anyObject() );
	CCPoint touchPoint = touch->getLocationInView();
	touchPoint = CCDirector::sharedDirector()->convertToGL( touchPoint );
	CCRect rc1 = pSprite3->boundingBox();
	
	CCRect rc2 = look->boundingBox();
	//if (rc2.containsPoint(touchPoint))
	//{
	//	shuffle();
	//	//getPoker(); 
	//	paint();
	//	compare();
	//	
	//}


}

void HelloWorld::shuffle()//洗牌函数
{   
	int temp;
	for(int i=0;i<52;i++)
	cart[i]=i;
	srand(time(NULL));//生成一个真随机数
	for(int i=0;i<52;i++)//用for循环实现洗牌
	{   
		int c;
		c=rand()%52;
		temp=cart[i];
		cart[i]=cart[c];
		cart[c]=temp;
	}
}

void HelloWorld::paint()
{
	int i;
	a[0]=cart[0];
	a[1]=cart[1];
	a[2]=cart[34];
	for (i=0;i<3;i++)
	{
		pai1[i]=getPhoto(a[i]);
		
	}
	b[0]=cart[2];
	b[1]=cart[3];
	b[2]=cart[47];
	for (i=0;i<3;i++)
	{
		pai2[i]=getPhoto(b[i]);

	}
	
}
void HelloWorld::lookmine()
{
	int j;
	for (j=0;j<3;j++)
	{
		pai1[j]->setPosition(ccp(size.width/2+j*50,95));
		this->addChild(pai1[j],0);
	}

}
CCSprite* HelloWorld::getPhoto(int i)
{
	CCSprite* temp;
	switch (i)
	{
	case 0:
	temp = CCSprite::create("21.png");break;
	case 1:
	temp = CCSprite::create("22.png");break;
	case 2:
	temp = CCSprite::create("23.png");break;
	case 3:
	temp = CCSprite::create("24.png");break;
	case 4:
	temp = CCSprite::create("31.png");break;
	case 5:
	temp = CCSprite::create("32.png");break;
	case 6:
	temp = CCSprite::create("33.png");break;
	case 7:
	temp = CCSprite::create("34.png");break;


	case 8:
	temp = CCSprite::create("41.png");break;
	case 9:
	temp = CCSprite::create("42.png");break;
	case 10:
	temp = CCSprite::create("43.png");break;
	case 11:
	temp = CCSprite::create("44.png");break;
	case 12:
	temp = CCSprite::create("51.png");break;
	case 13:
	temp = CCSprite::create("52.png");break;
	case 14:
	temp = CCSprite::create("53.png");break;
	case 15:
	temp = CCSprite::create("54.png");break;

	case 16:
	temp = CCSprite::create("61.png");break;
	case 17:
	temp = CCSprite::create("62.png");break;
	case 18:
	temp = CCSprite::create("63.png");break;
	case 19:
	temp = CCSprite::create("64.png");break;
	case 20:
	temp = CCSprite::create("71.png");break;
	case 21:
	temp = CCSprite::create("72.png");break;
	case 22:
	temp = CCSprite::create("73.png");break;
	case 23:
	temp = CCSprite::create("74.png");break;



	case 24:
	temp = CCSprite::create("81.png");break;
	case 25:
	temp = CCSprite::create("82.png");break;
	case 26:
	temp = CCSprite::create("83.png");break;
	case 27:
	temp = CCSprite::create("84.png");break;
	case 28:
	temp = CCSprite::create("91.png");break;
	case 29:
	temp = CCSprite::create("92.png");break;
	case 30:
	temp = CCSprite::create("93.png");break;
	case 31:
	temp = CCSprite::create("94.png");break;


	case 32:
	temp = CCSprite::create("101.png");break;
	case 33:
	temp = CCSprite::create("102.png");break;
	case 34:
	temp = CCSprite::create("103.png");break;
	case 35:
	temp = CCSprite::create("104.png");break;
	case 36:
	temp = CCSprite::create("1101.png");break;
	case 37:
	temp = CCSprite::create("1102.png");break;
	case 38:
	temp = CCSprite::create("1103.png");break;
	case 39:
	temp = CCSprite::create("1104.png");break;

	case 40:
	temp = CCSprite::create("1201.png");break;
	case 41:
	temp = CCSprite::create("1202.png");break;
	case 42:
	temp = CCSprite::create("1203.png");break;
	case 43:
	temp = CCSprite::create("1204.png");break;
	case 44:
	temp = CCSprite::create("1301.png");break;
	case 45:
	temp = CCSprite::create("1302.png");break;
	case 46:
	temp = CCSprite::create("1303.png");break;
	case 47:
	temp = CCSprite::create("1304.png");break;


	case 48:
	temp = CCSprite::create("1401.png");break;
	case 49:
	temp = CCSprite::create("1402.png");break;
	case 50:
	temp = CCSprite::create("1403.png");break;
	case 51:
	temp = CCSprite::create("1404.png");break;
	}
	return temp;
}

void HelloWorld::compare()
{
	int i,j;
	int p;
	for (i=0;i<3;i++)
	{
		for (j=i+1;j<3;j++)
			if (a[j]>a[i])
			{
				p=a[i];a[i]=a[j];a[j]=p;
			}
	}
	for (i=0;i<3;i++)
	{
		for (j=i+1;j<3;j++)
			if (b[j]>b[i])
			{
				p=b[i];b[i]=b[j];b[j]=p;
			}
	}
	wo=getScore(a);
	ta=getScore(b);
	if (wo>ta) win();
	else if (wo<ta) lose();
	else if (wo==ta) recompare();

}
void HelloWorld::win()
{
ying->setVisible(true);
ready->setVisible(true);
ready->setEnabled(true);
awardGold(jiang*2);
menu->setVisible(false);
genzhu->setVisible(false);
genzhu->setEnabled(false);
kanpai->setVisible(false);
kanpai->setEnabled(false);
bipai->setVisible(false);
bipai->setEnabled(false);
fangqi->setVisible(false);
fangqi->setEnabled(false);

pSprite3->setVisible(false);
pSprite3->setEnabled(false);
look->setEnabled(false);
//pSprite3->setVisible(true);
lookmine();
int j;
for (j=0;j<3;j++)
{
	pai2[j]->setPosition(ccp(size.width/2+j*50,size.height/2+280));
	this->addChild(pai2[j],0);
}
for (int i=0;i<6;i++)
{
	poker[i]->setPosition(ccp(size.width/2,415));
}

}
void HelloWorld::lose()
{
	shu->setVisible(true);
	ready->setVisible(true);
	ready->setEnabled(true);;

	menu->setVisible(false);
	genzhu->setVisible(false);
	genzhu->setEnabled(false);
	kanpai->setVisible(false);
	kanpai->setEnabled(false);
	bipai->setVisible(false);
	bipai->setEnabled(false);
	fangqi->setVisible(false);
	fangqi->setEnabled(false);
	pSprite3->setVisible(false);
	pSprite3->setEnabled(false);
	look->setEnabled(false);
	lookmine();
	int j;
	for (j=0;j<3;j++)
	{
		pai2[j]->setPosition(ccp(size.width/2+j*50,size.height/2+280));
		this->addChild(pai2[j],0);
	}
	for (int i=0;i<6;i++)
	{
		//poker[i]=CCSprite::create("gold_loginCard.png");
		poker[i]->setPosition(ccp(size.width/2,415));
		//poker[i]->setScale(0.65);
		//this->addChild(poker[i], 0);
	}
}
void HelloWorld::recompare()
{
	if (wo==7 || wo==6 || wo==5 || wo==4 || wo==2 )
	{
		if (a[0]/4>b[0]/4) win();
		else if (a[0]/4<b[0]/4) lose();
		else if (a[0]/4==b[0]/4)
		{
			if (a[1]/4>b[1]/4) win();
			else if (a[1]/4<b[1]/4) lose();
			else if (a[1]/4==b[1]/4)
			{
				if (a[2]/4>b[2]/4) win();
				else if (a[2]/4<b[2]/4) lose();
			}
		}


	}
	if (wo==3) 
	{
		int wo1;
		int ta1;
		int i;
		int j;
		if (a[0]/4==a[1]/4) {wo1=a[0]/4;i=a[2]/4;}
		if (a[0]/4==a[2]/4) {wo1=a[0]/4;i=a[1]/4;}
		if (a[2]/4==a[1]/4) {wo1=a[1]/4;i=a[0]/4;}

		if (b[0]/4==b[1]/4) {ta1=b[0]/4;j=b[2]/4;}
		if (b[0]/4==b[2]/4) {ta1=b[0]/4;j=b[1]/4;}
		if (b[2]/4==b[1]/4) {ta1=b[1]/4;j=b[0]/4;}
		if (wo1>ta1) win();
		else if (wo1<ta1) lose();
		else 
		{	if (i>j) win();
		else if (i<j) lose();
		}

	}
}

int HelloWorld::leopard(int a[3])//判断是不是豹子
{
	if(a[1]/4==a[2]/4&&a[1]/4==a[0]/4)
		return 1;
	else
		return 0;
}
int HelloWorld::sequence(int a[3])//判断是不是同花顺
{
	if(a[0]%4==a[1]%4&&a[0]%4==a[2]%4)
	{
		if(staight(a))
			return 1;
	}
	return 0;
}
int HelloWorld::staight(int a[3])//判断是不是顺子
{
	int c1=a[0]/4;
	int c2=a[1]/4;
	int c3=a[2]/4;
	if((c1+1==c2&&c2+1==c3)||(c1+1==c3&&c3+1==c2)||(c2+1==c3&&c3+1==c1)||(c2+1==c1&&c1+1==c3)||(c3+1==c1&&c1+1==c2)||(c3+1==c2&&c2+1==c1))
		return 1;
	else 
		return 0;
}
int HelloWorld::samecolor(int a[3])//判断是不是金花（同花不同顺子）
{
	if(a[0]%4==a[1]%4&&a[0]%4==a[2]%4)
		return 1;
	else 
		return 0;
}
int HelloWorld::brother(int a[3])//对子
{
	if((a[0]/4==a[1]/4)||(a[0]/4==a[2]/4)||(a[1]/4==a[2]/4))
		return 1;
	else
		return 0;
}
int HelloWorld::HighCard(int a[3])//特殊
{
	if(a[0]%13!=a[1]%13&&a[1]%13!=a[2]%13&&a[0]%13!=a[2]%13)
	{
		if((a[0]/4==0&&a[1]/4==1&&a[2]/4==3)||(a[1]/4==0&&a[0]/4==1&&a[2]/4==3)||(a[0]/4==0&&a[2]/4==1&&a[1]/4==3)||(a[1]/4==0&&a[2]/4==1&&a[0]/4==3)||(a[2]/4==0&&a[0]/4==1&&a[1]/4==3)||(a[2]/4==0&&a[1]/4==1&&a[0]/4==3))
			return 1;
	}
	return 0;
}

int HelloWorld::getScore(int a[3])//比较
{
	if(leopard(a))
		return 7;
	else
	{
		if(sequence(a)==1)
			return 6;
		else
		{
			if(samecolor(a)==1)
				return 5;
			else
			{
				if(staight(a)==1)
					return 4;
				else
				{
					if(brother(a)==1)
						return 3;
					else
					{
						if(HighCard(a))
							return 1;
						else return 2;
					}
				}
			}
		}
	}
}