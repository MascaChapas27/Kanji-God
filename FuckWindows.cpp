#include "FuckWindows.hpp"

std::map<int, std::wstring> FuckWindows::kanjisForWindows = {
    {5, L"一\nOne\nイチ\nイツ\n\nひと\nーーーー\n八\nEight\nハチ\n\nや\nやっ\nーーーー\n人\nPerson\nジン\nニン\n\nひと\nーーーー\n二\nTwo\nニ\n\nふた\nーーーー\n入\nEnter\nニュウ\n\nい\nはい\nーーーー\n十\nTen\nジュウ\nジッ\n\nと\nとお\nーーーー\n七\nSeven\nシチ\n\nなな\nーーーー\n九\nNine\nキュウ\nク\n\nここの\nーーーー\n小\nLittle\nショウ\n\nお\nこ\nちい\nーーーー\n上\nAbove\nジョウ\n\nあ\nうえ\nかみ\nのぼ\nーーーー\n下\nBelow\nカ\nゲ\n\nお\nくだ\nさ\nした\nしも\nもと\nーーーー\n川\nRiver\nセン\n\nかわ\nーーーー\n三\nThree\nサン\n\nみ\nみっ\nーーーー\n山\nMountain\nサン\n\nやま\nーーーー\n口\nMouth\nコウ\nク\n\nくち\nーーーー\n土\nSoil\nド\nト\n\nつち\nーーーー\n千\nThousand\nセン\n\nち\nーーーー\n大\nLarge\nダイ\nタイ\n\nおお\nーーーー\n子\nChild\nシ\nス\n\nこ\nーーーー\n万\nTen thousand\nマン\nバン\n\nーーーー\n女\nWoman\nジョ\nニョ\n\nおんな\nめ\nーーーー\n六\nSix\nロク\n\nむ\nむっ\nーーーー\n少\nFew\nショウ\n\nすく\nすこ\nーーーー\n火\nFire\nカ\n\nひ\nーーーー\n父\nFather\nフ\n\nちち\nーーーー\n今\nNow\nコン\nキン\n\nいま\nーーーー\n水\nWater\nスイ\n\nみず\nーーーー\n午\nNoon\nゴ\n\nーーーー\n分\nPart\nブン\nブ\nフン\n\nわ\nーーーー\n手\nHand\nシュ\n\nて\nーーーー\n天\nHeavens\nテン\n\nあめ\nーーーー\n日\nDay\nニチ\nジツ\n\nか\nひ\nーーーー\n木\nTree\nボク\nモク\n\nき\nーーーー\n中\nIn\nチュウ\n\nなか\nーーーー\n月\nMonth\nゲツ\nガツ\n\nつき\nーーーー\n五\nFive\nゴ\n\nいつ\nーーーー\n友\nFriend\nユウ\n\nとも\nーーーー\n円\nCircle\nエン\n\nまる\nーーーー\n立\nStand up\nリツ\n\nた\nーーーー\n北\nNorth\nホク\n\nきた\nーーーー\n半\nHalf\nハン\n\nなか\nーーーー\n外\nOutside\nガイ\nゲ\n\nそと\nはず\nほか\nーーーー\n右\nRight\nウ\nユウ\n\nみぎ\nーーーー\n出\nExit\nシュツ\n\nだ\nで\nーーーー\n古\nOld\nコ\n\nふる\nーーーー\n生\nLife\nセイ\nショウ\n\nい\nう\nお\nき\nなま\nは\nーーーー\n左\nLeft\nサ\n\nひだり\nーーーー\n四\nFour\nシ\n\nよ\nよっ\nよん\nーーーー\n本\nBook\nホン\n\nもと\nーーーー\n白\nWhite\nハク\nビャク\n\nしろ\nーーーー\n目\nEye\nモク\n\nめ\nーーーー\n母\nMama\nボ\n\nはは\nーーーー\n行\nGoing\nコウ\nギョウ\n\nい\nおこな\nゆ\nーーーー\n多\nMany\nタ\n\nおお\nーーーー\n名\nName\nメイ\nミョウ\n\nな\nーーーー\n年\nYear\nネン\n\nとし\nーーーー\n会\nMeeting\nカイ\nエ\n\nあ\nーーーー\n先\nBefore\nセン\n\nさき\nーーーー\n耳\nEar\nジ\n\nみみ\nーーーー\n百\nHundred\nヒャク\n\nーーーー\n気\nSpirit\nキ\nケ\n\nーーーー\n休\nRest\nキュウ\n\nやす\nーーーー\n安\nRelax\nアン\n\nやす\nーーーー\n西\nWest\nセイ\nサイ\n\nにし\nーーーー\n毎\nEvery\nマイ\n\nーーーー\n言\nSay\nゲン\nゴン\n\nい\nこと\nーーーー\n足\nLeg\nソク\n\nあし\nた\nーーーー\n社\nCompany\nシャ\n\nやしろ\nーーーー\n花\nFlower\nカ\n\nはな\nーーーー\n何\nWhat\nカ\n\nなに\nーーーー\n来\nCome\nライ\n\nきた\nく\nーーーー\n見\nSee\nケン\n\nみ\nーーーー\n車\nCar\nシャ\n\nくるま\nーーーー\n男\nMale\nダン\nナン\n\nおとこ\nーーーー\n学\nStudy\nガク\n\nまな\nーーーー\n空\nEmpty\nクウ\n\nあ\nから\nす\nそら\nーーーー\n店\nStore\nテン\n\nみせ\nーーーー\n金\nGold\nキン\nコン\n\nかね\nーーーー\n雨\nRain\nウ\n\nあめ\nーーーー\n長\nLong\nチョウ\n\nなが\nーーーー\n東\nEast\nトウ\n\nひがし\nーーーー\n国\nCountry\nコク\n\nくに\nーーーー\n食\nEat\nショク\n\nく\nた\nーーーー\n前\nIn front\nゼン\n\nまえ\nーーーー\n後\nBehind\nゴ\nコウ\n\nあと\nうし\nおく\nのち\nーーーー\n南\nSouth\nナン\n\nみなみ\nーーーー\n校\nSchool\nコウ\n\nーーーー\n時\nTime\nジ\n\nとき\nーーーー\n高\nTall\nコウ\n\nたか\nーーーー\n書\nWrite\nショ\n\nか\nーーーー\n魚\nFish\nギョ\n\nうお\nさかな\nーーーー\n週\nWeek\nシュウ\n\nーーーー\n飲\nDrink\nイン\n\nの\nーーーー\n道\nRoad-way\nドウ\n\nみち\nーーーー\n買\nBuy\nバイ\n\nか\nーーーー\n間\nInterval\nカン\nケン\n\nあいだ\nま\nーーーー\n話\nTale\nワ\n\nはな\nはなし\nーーーー\n新\nNew\nシン\n\nあたら\nあら\nにい\nーーーー\n電\nElectricity\nデン\n\nーーーー\n読\nRead\nドク\nトク\n\nよ\nーーーー\n語\nWord\nゴ\n\nかた\nーーーー\n駅\nStation\nエキ\n\nーーーー\n聞\nHear\nブン\nモン\n\nき\nーーーー\n#\n"},
    {4, L"力\nPower\nリョク\nリキ\n\nりょく\nーーーー\n工\nCraft\nコウ\nク\n\nーーーー\n夕\nEvening\nセキ\n\nゆう\nーーーー\n心\nHeart\nシン\n\nこころ\nーーーー\n止\nStop\nシ\n\nと\nーーーー\n太\nPlump\nタイ\nタ\n\nふと\nーーーー\n不\nNegative\nフ\nブ\n\nーーーー\n犬\nDog\nケン\n\nいぬ\nーーーー\n方\nDirection\nホウ\n\nかた\nーーーー\n牛\nCow\nギュウ\n\nうし\nーーーー\n文\nSentence\nブン\nモン\n\nふみ\nーーーー\n元\nBeginning\nゲン\nガン\n\nもと\nーーーー\n引\nPull\nイン\n\nひ\nーーーー\n切\nCut\nセツ\n\nき\nーーーー\n区\nWard\nク\n\nーーーー\n以\nBy means of\nイ\n\nーーーー\n冬\nWinter\nトウ\n\nふゆ\nーーーー\n主\nLord\nシュ\n\nおも\nぬし\nーーーー\n正\nCorrect\nセイ\nショウ\n\nただ\nまさ\nーーーー\n代\nSubstitute\nダイ\nタイ\n\nか\nしろ\nよ\nーーーー\n広\nWide\nコウ\n\nひろ\nーーーー\n兄\nElder brother\nケイ\nキョウ\n\nあに\nーーーー\n台\nPedestal\nダイ\nタイ\n\nーーーー\n市\nMarket\nシ\n\nいち\nーーーー\n仕\nAttend\nシ\n\nつか\nーーーー\n去\nGone\nキョ\nコ\n\nさ\nーーーー\n写\nCopy\nシャ\n\nうつ\nーーーー\n世\nGeneration\nセイ\nセ\n\nよ\nーーーー\n田\nRice field\nデン\n\nた\nーーーー\n民\nPeople\nミン\n\nたみ\nーーーー\n用\nUtilize\nヨウ\n\nもち\nーーーー\n光\nRay\nコウ\n\nひか\nひかる\nーーーー\n合\nFit\nゴウ\nガッ\n\nあ\nーーーー\n池\nPond\nチ\n\nいけ\nーーーー\n字\nCharacter\nジ\n\nあざ\nーーーー\n死\nDeath\nシ\n\nし\nーーーー\n色\nColor\nショク\nシキ\n\nいろ\nーーーー\n早\nEarly\nソウ\nサッ\n\nはや\nーーーー\n自\nOneself\nジ\nシ\n\nみずか\nーーーー\n地\nGround\nチ\nジ\n\nーーーー\n回\nTimes\nカイ\n\nまわ\nーーーー\n有\nPossess\nユウ\nウ\n\nあ\nーーーー\n好\nFond\nコウ\n\nこの\nす\nーーーー\n肉\nMeat\nニク\n\nーーーー\n考\nConsider\nコウ\n\nかんが\nーーーー\n同\nSame\nドウ\n\nおな\nーーーー\n作\nMake\nサク\nサ\n\nつく\nーーーー\n赤\nRed\nセキ\n\nあか\nーーーー\n走\nRun\nソウ\n\nはし\nーーーー\n声\nVoice\nセイ\n\nこえ\nーーーー\n住\nDwell\nジュウ\n\nす\nーーーー\n私\nPrivate\nシ\n\nわたし\nわたくし\nーーーー\n近\nNear\nキン\n\nちか\nーーーー\n村\nVillage\nソン\n\nむら\nーーーー\n町\nTown\nチョウ\n\nまち\nーーーー\n究\nResearch\nキュウ\n\nきわ\nーーーー\n売\nSell\nバイ\n\nう\nーーーー\n別\nSeparate\nベツ\n\nわか\nーーーー\n低\nLower\nテイ\n\nひく\nーーーー\n体\nBody\nタイ\nテイ\n\nからだ\nーーーー\n弟\nYounger bother\nテイ\n\nおとうと\nーーーー\n医\nDoctor\nイ\n\nーーーー\n図\nMap\nズ\nト\n\nはか\nーーーー\n注\nPour\nチュウ\n\nそそ\nーーーー\n歩\nWalk\nホ\nブ\n\nあゆ\nある\nーーーー\n京\nCapital\nキョウ\nケイ\n\nーーーー\n知\nKnow\nチ\n\nし\nーーーー\n所\nPlace\nショ\n\nところ\nーーーー\n夜\nNight\nヤ\n\nよ\nよる\nーーーー\n味\nFlavor\nミ\n\nあじ\nーーーー\n門\nGates\nモン\n\nかど\nーーーー\n始\nCommence\nシ\n\nはじ\nーーーー\n林\nGrove\nリン\n\nはやし\nーーーー\n英\nEngland\nエイ\n\nーーーー\n物\nThing\nブツ\nモツ\n\nもの\nーーーー\n青\nBlue\nセイ\n\nあお\nーーーー\n姉\nElder sister\nシ\n\nあね\nーーーー\n使\nUse\nシ\n\nつか\nーーーー\n明\nBright\nメイ\nミョウ\n\nあ\nあか\nあき\nーーーー\n者\nSomeone\nシャ\n\nもの\nーーーー\n妹\nYounger sister\nマイ\n\nいもうと\nーーーー\n画\nBrush stroke\nガ\nカク\n\nーーーー\n服\nClothing\nフク\n\nーーーー\n事\nMatter\nジ\n\nこと\nーーーー\n洋\nOcean\nヨウ\n\nーーーー\n計\nPlot\nケイ\n\nはか\nーーーー\n洗\nWash\nセン\n\nあら\nーーーー\n茶\nTea\nチャ\nサ\n\nーーーー\n秋\nAutumn\nシュウ\n\nあき\nーーーー\n首\nNeck\nシュ\n\nくび\nーーーー\n音\nSound\nオン\nイン\n\nおと\nね\nーーーー\n急\nHurry\nキュウ\n\nいそ\nーーーー\n送\nSend off\nソウ\n\nおく\nーーーー\n品\nGoods\nヒン\n\nしな\nーーーー\n思\nThink\nシ\n\nおも\nーーーー\n待\nWait\nタイ\n\nま\nーーーー\n県\nPrefecture\nケン\n\nーーーー\n室\nRoom\nシツ\n\nむろ\nーーーー\n持\nHold\nジ\n\nも\nーーーー\n界\nWorld\nカイ\n\nーーーー\n研\nPolish\nケン\n\nと\nーーーー\n発\nDischarge\nハツ\nホツ\n\nーーーー\n映\nReflect\nエイ\n\nうつ\nは\nーーーー\n度\nDegrees\nド\n\nたび\nーーーー\n海\nSea\nカイ\n\nうみ\nーーーー\n昼\nDaytime\nチュウ\n\nひる\nーーーー\n風\nWind\nフウ\n\nかぜ\nーーーー\n屋\nRoof\nオク\n\nや\nーーーー\n乗\nRide\nジョウ\n\nの\nーーーー\n春\nSpringtime\nシュン\n\nはる\nーーーー\n便\nConvenience\nベン\nビン\n\nたよ\nーーーー\n重\nHeavy\nジュウ\nチョウ\n\nえ\nおも\nかさ\nーーーー\n建\nBuild\nケン\n\nた\nーーーー\n家\nHouse\nカ\nケ\n\nいえ\nや\nーーーー\n料\nFee\nリョウ\n\nーーーー\n旅\nTrip\nリョ\n\nたび\nーーーー\n起\nRouse\nキ\n\nお\nーーーー\n特\nSpecial\nトク\n\nーーーー\n院\nInst.\nイン\n\nーーーー\n員\nEmployee\nイン\n\nーーーー\n借\nBorrow\nシャク\n\nか\nーーーー\n紙\nPaper\nシ\n\nかみ\nーーーー\n弱\nWeak\nジャク\n\nよわ\nーーーー\n病\nIll\nビョウ\n\nや\nやまい\nーーーー\n帰\nHomecoming\nキ\n\nかえ\nーーーー\n真\nTrue\nシン\n\nま\nーーーー\n夏\nSummer\nカ\n\nなつ\nーーーー\n勉\nExertion\nベン\n\nーーーー\n通\nTraffic\nツウ\n\nとう\nかよ\nーーーー\n菜\nVegetable\nサイ\n\nな\nーーーー\n堂\nPublic chamber\nドウ\n\nーーーー\n鳥\nBird\nチョウ\n\nとり\nーーーー\n終\nEnd\nシュウ\n\nお\nーーーー\n族\nTribe\nゾク\n\nーーーー\n習\nLearn\nシュウ\n\nなら\nーーーー\n黒\nBlack\nコク\n\nくろ\nーーーー\n産\nProducts\nサン\n\nう\nうぶ\nーーーー\n進\nAdvance\nシン\n\nすす\nーーーー\n悪\nBad\nアク\nオ\n\nわる\nーーーー\n教\nTeach\nキョウ\n\nおし\nおそ\nーーーー\n転\nRevolve\nテン\n\nころ\nーーーー\n問\nQuestion\nモン\n\nと\nーーーー\n野\nPlains\nヤ\n\nの\nーーーー\n強\nStrong\nキョウ\nゴウ\n\nし\nつよ\nーーーー\n都\nMetropolis\nト\nツ\n\nーーーー\n理\nLogic\nリ\n\nーーーー\n動\nMove\nドウ\n\nうご\nーーーー\n答\nSolution\nトウ\n\nこた\nーーーー\n短\nShort\nタン\n\nみじか\nーーーー\n貸\nLend\nタイ\n\nか\nーーーー\n寒\nCold\nカン\n\nさむ\nーーーー\n着\nDon\nチャク\n\nき\nつ\nーーーー\n場\nLocation\nジョウ\n\nば\nーーーー\n森\nForest\nシン\n\nもり\nーーーー\n飯\nMeal\nハン\n\nめし\nーーーー\n集\nGather\nシュウ\n\nあつ\nつど\nーーーー\n朝\nMorning\nチョウ\n\nあさ\nーーーー\n運\nCarry\nウン\n\nはこ\nーーーー\n軽\nLightly\nケイ\n\nかる\nかろ\nーーーー\n開\nOpen\nカイ\n\nあ\nひら\nーーーー\n暑\nSultry\nショ\n\nあつ\nーーーー\n試\nTest\nシ\n\nこころ\nため\nーーーー\n楽\nMusic\nガク\nラク\n\nたの\nーーーー\n遠\nDistant\nエン\n\nとお\nーーーー\n意\nIdea\nイ\n\nーーーー\n漢\nSino-\nカン\n\nーーーー\n暗\nDarkness\nアン\n\nくら\nーーーー\n業\nProfession\nギョウ\nゴウ\n\nわざ\nーーーー\n働\nWork\nドウ\n\nはたら\nーーーー\n説\nRumor\nセツ\n\nと\nーーーー\n歌\nSong\nカ\n\nうた\nーーーー\n銀\nSilver\nギン\n\nーーーー\n質\nSubstance\nシツ\nシチ\n\nーーーー\n頭\nHead\nトウ\nズ\n\nあたま\nかしら\nーーーー\n薬\nMedicine\nヤク\n\nくすり\nーーーー\n館\nBuilding\nカン\n\nやかた\nーーーー\n親\nParent\nシン\n\nおや\nした\nーーーー\n顔\nFace\nガン\n\nかお\nーーーー\n験\nVerification\nケン\n\nーーーー\n題\nTopic\nダイ\n\nーーーー\n曜\nWeekday\nヨウ\n\nーーーー\n#"},
    {3, L"亡\nDeceased\nボウ\n\nな\nーーーー\n才\nGenius\nサイ\n\nーーーー\n与\nBestow\nヨ\n\nあた\nーーーー\n欠\nLack\nケツ\n\nか\nーーーー\n王\nKing\nオウ\n\nーーーー\n化\nChange\nカ\nケ\n\nば\nーーーー\n予\nBeforehand\nヨ\n\nーーーー\n夫\nHusband\nフ\n\nおっと\nーーーー\n支\nBranch\nフ\n\nおっと\nーーーー\n内\nInside\nナイ\n\nうち\nーーーー\n互\nMutually\nゴ\n\nたが\nーーーー\n収\nIncome\nシュウ\n\nおさ\nーーーー\n反\nAnti-\nハン\n\nそ\nーーーー\n必\nInvariably\nヒツ\n\nかなら\nーーーー\n示\nShow\nジ\nシ\n\nしめ\nーーーー\n礼\nSalutation\nレイ\nライ\n\nーーーー\n平\nEven\nヘイ\nビョウ\n\nたい\nひら\nーーーー\n込\nCrowded\n\nこ\nーーーー\n付\nAdhere\nフ\n\nつ\nーーーー\n石\nStone\nセキ\n\nいし\nーーーー\n打\nStrike\nダ\n\nう\nーーーー\n失\nLose\nシツ\n\nうしな\nーーーー\n仏\nPay\nフツ\n\nはら\nーーーー\n号\nNickname\nゴウ\n\nーーーー\n加\nAdd\nカ\n\nくわ\nーーーー\n未\nNot yet\nミ\n\nーーーー\n末\nExtremity\nマツ\nバツ\n\nすえ\nーーーー\n処\nDispose\nショ\n\nーーーー\n犯\nCrime\nハン\n\nおか\nーーーー\n申\nSpeaketh\nシン\n\nもう\nーーーー\n他\nOther\nタ\n\nほか\nーーーー\n由\nWherefore\nユ\nユウ\n\nよし\nーーーー\n次\nNext\nジ\nシ\n\nつ\nつぎ\nーーーー\n交\nMingle\nコウ\n\nか\nま\nまじ\nーーーー\n忙\nBusy\nボウ\n\nいそぐ\nーーーー\n守\nGuard\nシュ\n\nまも\nも\nーーーー\n式\nStyle\nシキ\n\nーーーー\n向\nYonder\nコウ\n\nむ\nーーーー\n全\nWhole\nゼン\n\nすべ\nまった\nーーーー\n米\nRice\nベイ\nマイ\n\nこめ\nーーーー\n共\nTogether\nキョウ\n\nとも\nーーーー\n当\nHit\nトウ\n\nあ\nーーーー\n伝\nTransmit\nデン\n\nつた\nーーーー\n任\nResponsibility\nニン\n\nまか\nーーーー\n列\nFile\nレツ\n\nーーーー\n宅\nHome\nタク\n\nーーーー\n件\nAffair\nケン\n\nくだん\nーーーー\n存\nSuppose\nソン\nゾン\n\nーーーー\n在\nExist\nザイ\n\nあ\nーーーー\n老\nOld man\nロウ\n\nおふ\nーーーー\n成\nTurn into\nセイ\n\nな\nーーーー\n吸\nSuck\nキュウ\n\nす\nーーーー\n争\nContend\nソウ\n\nあらそ\nーーーー\n危\nDangerous\nキ\n\nあぶ\nあや\nーーーー\n両\nBoth\nリョウ\n\nーーーー\n曲\nBend\nキョク\n\nま\nーーーー\n因\nCause\nイン\n\nよ\nーーーー\n忘\nForget\nボウ\n\nわす\nーーーー\n吹\nBlow\nスイ\n\nふ\nーーーー\n似\nSimilar\nジ\n\nに\nーーーー\n冷\nCool\nレイ\n\nさ\nつめ\nひ\nーーーー\n求\nRequest\nキュウ\n\nもと\nーーーー\n対\nVis-a-vis\nタイ\nツイ\n\nーーーー\n位\nRank\nイ\n\nくらい\nーーーー\n労\nLabor\nロウ\n\nーーーー\n状\nStatus quo\nジョウ\n\nーーーー\n形\nShape\nケイ\nギョウ\n\nかた\nかたち\nーーーー\n完\nPerfect\nカン\n\nーーーー\n決\nDecide\nケツ\n\nき\nーーーー\n余\nToo much\nヨ\n\nあま\nーーーー\n否\nNegate\nヒ\n\nいな\nーーーー\n良\nGood\nリョウ\n\nい\nよ\nーーーー\n折\nFold\nセツ\n\nお\nおり\nーーーー\n告\nRevelation\nコク\n\nつ\nーーーー\n迎\nWelcome\nゲイ\n\nむか\nーーーー\n判\nJudgement\nハン\nバン\n\nーーーー\n初\nFirst time\nショ\n\nうい\nそ\nはじ\nはつ\nーーーー\n利\nProfit\nリ\n\nき\nーーーー\n役\nDuty\nヤク\nエキ\n\nーーーー\n束\nBundle\nソク\n\nたば\nーーーー\n返\nReturn\nヘン\n\nかえ\nーーーー\n助\nHelp\nジョ\n\nすけ\nたす\nーーーー\n投\nThrow\nトウ\n\nな\nーーーー\n局\nBureau\nキョク\n\nーーーー\n努\nToil\nド\n\nつと\nーーーー\n抜\nSlip out\nバツ\n\nぬ\nーーーー\n戻\nRe-\nレイ\n\nもど\nーーーー\n更\nGrow late\nコウ\n\nさら\nふ\nーーーー\n君\nOld boy\nクン\n\nきみ\nーーーー\n困\nQuandary\nコン\n\nこま\nーーーー\n泳\nSwim\nエイ\n\nおよ\nーーーー\n治\nReign\nジ\nチ\n\nおさ\nなお\nーーーー\n法\nMethod\nホウ\n\nーーーー\n念\nWish\nネン\n\nーーーー\n呼\nCall\nコ\n\nよ\nーーーー\n非\nUn-\nヒ\n\nーーーー\n和\nHarmony\nワ\n\nなぎ\nやか\nーーーー\n定\nDetermine\nテイ\nジョウ\n\nさだ\nーーーー\n官\nBureaucrat\nカン\n\nーーーー\n命\nFate\nメイ\nミョウ\n\nいのち\nーーーー\n幸\nHappiness\nコウ\n\nさいわ\nさち\nしあわ\nーーーー\n突\nStab\nトツ\n\nつ\nーーーー\n受\nAccept\nジュ\n\nう\nーーーー\n到\nArrival\nトウ\n\nーーーー\n刻\nEngrave\nコク\n\nきざ\nーーーー\n供\nSumbit\nキョウ\n\nそな\nとも\nーーーー\n杯\nCupfuls\nハイ\n\nさかずき\nーーーー\n苦\nSuffering\nク\n\nくる\nにが\nーーーー\n放\nSet free\nホウ\n\nはな\nほう\nーーーー\n昔\nOnce upon a time\nセキ\n\nむかし\nーーーー\n性\nSex\nセイ\nショウ\n\nーーーー\n具\nTool\nグ\n\nーーーー\n育\nBring up\nイク\n\nそだ\nはぐく\nーーーー\n実\nReality\nジツ\n\nみ\nみの\nーーーー\n参\nVisit\nサン\n\nまい\nーーーー\n若\nYoung\nジャク\n\nも\nわか\nーーーー\n表\nSurface\nヒョウ\n\nあらわ\nおもて\nーーーー\n例\nExample\nレイ\n\nたと\nーーーー\n彼\nHe\nヒ\n\nかれ\nーーーー\n居\nReside\nキョ\n\nい\nーーーー\n易\nEasy\nエキ\nイ\n\nやさ\nーーーー\n怖\nDreadful\nフ\n\nこわ\nーーーー\n招\nBeckon\nショウ\n\nまね\nーーーー\n取\nTake\nシュ\n\nと\nーーーー\n抱\nEmbrace\nホウ\n\nいだ\nかか\nだ\nーーーー\n押\nPush\nオウ\n\nお\nーーーー\n制\nSystem\nセイ\n\nーーーー\n直\nStraightaway\nチョク\nジキ\n\nただ\nなお\nーーーー\n果\nFruit\nカ\n\nは\nーーーー\n妻\nWife\nサイ\n\nつま\nーーーー\n点\nSpot\nテン\n\nーーーー\n活\nLively\nカツ\n\nーーーー\n信\nFaith\nシン\n\nーーーー\n約\nPromise\nヤク\n\nーーーー\n昨\nYesterday\nサク\n\nーーーー\n政\nPolitics\nセイ\n\nまつりごと\nーーーー\n逃\nEscape\nトウ\n\nに\nのが\nーーーー\n科\nDepartment\nカ\n\nーーーー\n係\nPerson in charge\nケイ\n\nかか\nかかり\nーーーー\n背\nStature\nハイ\n\nせ\nせい\nそむ\nーーーー\n追\nChase\nツイ\n\nお\nーーーー\n皆\nAll\nカイ\n\nみな\nーーーー\n迷\nAstray\nメイ\n\nまよ\nーーーー\n負\nDefeat\nフ\n\nお\nま\nーーーー\n変\nUnusual\nヘン\n\nか\nーーーー\n退\nRetreat\nタイ\n\nしりぞ\nーーーー\n客\nGuest\nキャク\nカク\n\nーーーー\n怒\nAngry\nド\n\nいか\nおこ\nーーーー\n単\nSimple\nタン\n\nーーーー\n美\nBeauty\nビ\n\nうつく\nーーーー\n草\nGrass\nソウ\n\nくさ\nーーーー\n段\nGrade\nダン\n\nーーーー\n飛\nFly\nヒ\n\nと\nーーーー\n祖\nAncestor\nソ\n\nーーーー\n神\nGods\nシン\nジン\n\nかみ\nーーーー\n指\nFinger\nシ\n\nさ\nゆび\nーーーー\n限\nLimit\nゲン\n\nかぎ\nーーーー\n相\nInter-\nソウ\nショウ\n\nあい\nーーーー\n面\nMask\nメイ\n\nおも\nおもて\nつら\nーーーー\n要\nNeed\nヨウ\n\nい\nかなめ\nーーーー\n浮\nFloating\nフ\n\nう\nーーーー\n消\nExtinguish\nショウ\n\nき\nけ\nーーーー\n記\nScribe\nキ\n\nしる\nーーーー\n流\nCurrent\nリュウ\n\nなが\nーーーー\n恥\nShame\nチ\n\nは\nはじ\nーーーー\n笑\nLaugh\nショウ\n\nえ\nわら\nーーーー\n息\nBreath\nソク\n\nいき\nーーーー\n恐\nFear\nキョウ\n\nおそ\nーーーー\n容\nContain\nヨウ\n\nーーーー\n差\nDistinction\nサ\n\nさ\nーーーー\n徒\nJunior\nト\n\nーーーー\n途\nRoute\nト\n\nーーーー\n座\nSit\nザ\n\nすわ\nーーーー\n害\nHarm\nガイ\n\nーーーー\n馬\nHorse\nバ\n\nうま\nーーーー\n財\nProperty\nザイ\n\nーーーー\n除\nExcluse\nジョ\n\nのぞ\nーーーー\n原\nMeadow\nゲン\n\nはら\nーーーー\n格\nStatus\nカク\n\nーーーー\n倒\nOverthrow\nトウ\n\nたお\nーーーー\n破\nRend\nハ\n\nやぶ\nーーーー\n席\nSeat\nセキ\n\nーーーー\n庭\nCourtyard\nテイ\n\nにわ\nーーーー\n疲\nTired\nヒ\n\nつか\nーーーー\n速\nQuick\nソク\n\nすみ\nはや\nーーーー\n殺\nKill\nサツ\n\nころ\nーーーー\n能\nAbility\nノウ\n\nーーーー\n娘\nDaughter\n\nむすめ\nーーーー\n酒\nSake\nシュ\n\nさけ\nーーーー\n候\nClimate\nコウ\n\nそうろう\nーーーー\n残\nRemainder\nザン\n\nのこ\nーーーー\n師\nExpert\nシ\n\nーーーー\n留\nDetain\nリュウ\n\nと\nーーーー\n降\nDescend\nコウ\n\nお\nふ\nーーーー\n値\nPrice\nチ\n\nあたい\nね\nーーーー\n眠\nSleep\nミン\n\nねむ\nーーーー\n連\nTake along\nレン\n\nつ\nつら\nーーーー\n配\nDistribute\nハイ\n\nくば\nーーーー\n捕\nCatch\nホ\n\nつか\nと\nーーーー\n欲\nLonging\nヨク\n\nほ\nほっ\nーーーー\n窓\nWindow\nソウ\n\nまど\nーーーー\n許\nPermit\nキョ\n\nゆる\nーーーー\n球\nBall\nキュウ\n\nたま\nーーーー\n深\nDeep\nシン\n\nふか\nーーーー\n済\nFinish\nサイ\n\nす\nーーーー\n訪\nCall on\nホウ\n\nおとず\nたず\nーーーー\n常\nUsual\nジョウ\n\nつね\nとこ\nーーーー\n盗\nSteal\nトウ\n\nぬす\nーーーー\n術\nArt\nジュツ\n\nーーーー\n敗\nFailure\nハイ\n\nやぶ\nーーーー\n寄\nDraw near\nキ\n\nよ\nーーーー\n部\nSection\nブ\n\nーーーー\n掛\nHang\n\nか\nがかり\nーーーー\n貧\nPoverty\nヒン\nビン\n\nまず\nーーーー\n宿\nInn\nシュク\n\nやど\nーーーー\n雪\nSnow\nセツ\n\nゆき\nーーーー\n船\nShip\nセン\n\nふね\nーーーー\n得\nGain\nトク\n\nう\nえ\nーーーー\n責\nBlame\nセキ\n\nせ\nーーーー\n商\nMake a deal\nショウ\n\nあきな\nーーーー\n頂\nPlace on the head\nチョウ\n\nいただ\nいただき\nーーーー\n側\nSide\nソク\n\nがわ\nーーーー\n情\nFeelings\nジョウ\n\nなさ\nーーーー\n現\nPresent\nゲン\n\nあらわ\nーーーー\n探\nGrope\nタン\n\nさが\nさぐ\nーーーー\n経\nSutra\nケイ\nキョウ\n\nへ\nーーーー\n断\nSeverance\nダン\n\nことわ\nた\nーーーー\n規\nStandard\nキ\n\nーーーー\n望\nAmbition\nボウ\nモウ\n\nのぞ\nーーーー\n組\nAssociation\nソ\n\nく\nくみ\nーーーー\n険\nPrecipitous\nケン\n\nけわ\nーーーー\n務\nTask\nム\n\nつと\nーーーー\n猫\nCat\nビョウ\n\nねこ\nーーーー\n婚\nMarriage\nコン\n\nーーーー\n閉\nClosed\nヘイ\n\nし\nと\nーーーー\n婦\nLady\nフ\n\nーーーー\n偶\nAccidentally\nグウ\n\nーーーー\n悲\nSad\nヒ\n\nかな\nーーーー\n然\nSort of thing\nゼン\nネン\n\nーーーー\n等\nEtc.\nトウ\n\nひと\nーーーー\n登\nAscend\nトウ\nト\n\nのぼ\nーーーー\n落\nFall\nラク\n\nお\nーーーー\n港\nHarbor\nコウ\n\nみなと\nーーーー\n絵\nPicture\nカイ\nエ\n\nーーーー\n喜\nRejoice\nキ\n\nよろこ\nーーーー\n給\nSalary\nキュウ\n\nーーーー\n覚\nMemorize\nカク\n\nおぼ\nさ\nーーーー\n景\nScenery\nケイ\n\nーーーー\n渡\nTransit\nト\n\nわた\nーーーー\n達\nAccomplished\nタツ\n\nーーーー\n御\nHonorable\nギョ\nゴ\n\nおん\nーーーー\n割\nProportion\nカツ\n\nさ\nわ\nわり\nーーーー\n満\nFull\nマン\n\nみ\nーーーー\n晩\nNightfall\nバン\n\nーーーー\n富\nWealth\nフ\n\nと\nとみ\nーーーー\n遊\nPlay\nユウ\n\nあそ\nーーーー\n歯\nTooth\nシ\n\nは\nーーーー\n過\nOverdo\nカ\n\nあやま\nす\nーーーー\n散\nScatter\nサン\n\nち\nーーーー\n絶\nDiscontinue\nゼツ\n\nた\nーーーー\n程\nExtent\nテイ\n\nほど\nーーーー\n幾\nHow many\nキ\n\nいく\nーーーー\n偉\nAdmirable\nイ\n\nえら\nーーーー\n遅\nSlow\nチ\n\nおく\nおそ\nーーーー\n番\nTurn\nバン\n\nーーーー\n越\nSurpass\nエツ\n\nこ\nーーーー\n期\nPeriod\nキ\n\nーーーー\n晴\nClear up\nセイ\n\nは\nーーーー\n勤\nDiligence\nキン\n\nつと\nーーーー\n報\nReport\nホウ\n\nむく\nーーーー\n痛\nPain\nツウ\n\nいた\nーーーー\n葉\nLeaf\nヨウ\n\nは\nーーーー\n陽\nSunshine\nヨウ\n\nーーーー\n勝\nVictory\nショウ\n\nか\nまさ\nーーーー\n最\nUtmost\nサイ\n\nもっと\nーーーー\n備\nEquip\nビ\n\nそな\nーーーー\n費\nExpense\nヒ\n\nつい\nーーーー\n辞\nResign\nジ\n\nや\nーーーー\n愛\nLove\nアイ\n\nーーーー\n感\nEmotion\nカン\n\nーーーー\n想\nConcept\nソウ\n\nーーーー\n続\nContinue\nゾク\n\nつづ\nーーーー\n資\nAssets\nシ\n\nーーーー\n数\nNumber\nスウ\n\nかず\nかぞ\nーーーー\n路\nPath\nロ\n\nじ\nーーーー\n戦\nWar\nセン\n\nいくさ\nたたか\nーーーー\n罪\nGuilt\nザイ\n\nつみ\nーーーー\n夢\nDream\nム\n\nゆめ\nーーーー\n寝\nLie down\nシン\n\nね\nーーーー\n煙\nSmoke\nエン\n\nけむ\nけむり\nーーーー\n歳\nYear-end\nサイ\n\nーーーー\n福\nBlessing\nフク\n\nーーーー\n違\nDifference\nイ\n\nちが\nーーーー\n靴\nShoes\nカ\n\nくつ\nーーーー\n腹\nAbdomen\nフク\n\nはら\nーーーー\n解\nUnravel\nカイ\nゲ\n\nと\nーーーー\n置\nPlacement\nチ\n\nお\nーーーー\n園\nPark\nエン\n\nその\nーーーー\n演\nPerformance\nエン\n\nーーーー\n認\nAcknowledge\nニン\n\nみと\nーーーー\n鳴\nChirp\nメイ\n\nな\nーーーー\n疑\nDoubt\nギ\n\nうたが\nーーーー\n誤\nMistake\nゴ\n\nあやま\nーーーー\n察\nGuess\nサツ\n\nーーーー\n様\nEsq.\nヨウ\n\nさま\nーーーー\n適\nSuitable\nテキ\n\nーーーー\n際\nOccasion\nサイ\n\nきわ\nーーーー\n増\nIncrease\nゾウ\n\nふ\nま\nーーーー\n髪\nHair of the head\nハツ\n\nかみ\nーーーー\n緒\nThong\nショ\n\nお\nーーーー\n精\nRefined\nセイ\n\nーーーー\n関\nConnection\nカン\n\nかか\nせき\nーーーー\n慣\nAccustomed\nカン\n\nな\nーーーー\n墓\nLivelihood\nボ\n\nく\nーーーー\n雑\nMiscellaneous\nザツ\nゾウ\n\nーーーー\n静\nQuiet\nセイ\n\nしず\nーーーー\n種\nSpecies\nシュ\n\nたね\nーーーー\n構\nPosture\nコウ\n\nかま\nーーーー\n談\nDiscuss\nダン\n\nーーーー\n熱\nHeat\nネツ\n\nあつ\nーーーー\n箱\nBox\nはこ\n\nーーーー\n選\nElect\nセン\n\nえら\nーーーー\n賛\nApprove\nサン\n\nーーーー\n論\nArgument\nロン\n\nーーーー\n調\nTune\nチョウ\n\nしら\nととの\nーーーー\n確\nAssurance\nカク\n\nたし\nーーーー\n横\nSideways\nオウ\n\nよこ\nーーーー\n舞\nDance\nブ\n\nま\nまい\nーーーー\n権\nAuthority\nケン\n\nーーーー\n積\nVolume\nセキ\n\nつ\nーーーー\n頼\nTrust\nライ\n\nたの\nたよ\nーーーー\n機\nMechanism\nキ\n\nはた\nーーーー\n優\nTenderness\nユウ\n\nすぐ\nやさ\nーーーー\n類\nSort\nルイ\n\nたぐ\nーーーー\n職\nPost\nショク\n\nーーーー\n難\nDifficult\nナン\n\nかた\nむずか\nーーーー\n観\nOutlook\nカン\n\nーーーー\n識\nDiscriminating\nシキ\n\nーーーー\n警\nAdmonish\nケイ\n\nーーーー\n願\nPetition\nガン\n\nねが\nーーーー\n議\nDeliberation\nギ\n\nーーーー\n#"},
    {2, L"了\nComplete\nリョウ\n\nーーーー\n久\nLong time\nキュウ\n\nひさ\nーーーー\n干\nDry\nカン\n\nほ\nひ\nーーーー\n丸\nRound\nガン\n\nまる\nーーーー\n公\nPublic\nコウ\n\nおおやけ\nーーーー\n戸\nDoor\nコ\n\nと\nーーーー\n介\nJammed in\nカイ\n\nーーーー\n片\nOne-sided\nヘン\n\nかた\nーーーー\n仏\nBuddha\nブツ\n\nほとけ\nーーーー\n比\nCompare\nヒ\n\nくら\nーーーー\n毛\nFur\nモウ\n\nけ\nーーーー\n双\nPair\nソウ\n\nふた\nーーーー\n匹\nEqual\nヒツ\n\nひき\nーーーー\n占\nセン\n\nうらな\nし\nーーーー\n永\nEternity\nエイ\n\nなが\nーーーー\n氷\nIcicle\nヒョウ\n\nこおり\nひ\nーーーー\n庁\nGovernment office\nチョウ\n\nーーーー\n可\nCan\nカ\n\nーーーー\n玉\nJewel\nギョク\n\nたま\nーーーー\n令\nOrders\nレイ\n\nーーーー\n刊\nPublish\nカン\n\nーーーー\n札\nTag\nサツ\n\nふだ\nーーーー\n司\nDirector\nシ\n\nーーーー\n召\nSeduce\nショウ\n\nめ\nーーーー\n圧\nPressure\nアツ\n\nーーーー\n辺\nEnvirons\nヘン\n\nあた\nべ\nーーーー\n甘\nSweet\nカン\n\nあま\nーーーー\n巨\nGigantic\nキョ\n\nーーーー\n包\nWrap\nホウ\n\nつつ\nーーーー\n史\nHistory\nシ\n\nーーーー\n旧\nOlden times\nキュウ\n\nーーーー\n皿\nDish\n\nさら\nーーーー\n布\nLinen\nフ\n\nぬの\nーーーー\n皮\nPelt\nヒ\n\nかわ\nーーーー\n幼\nInfancy\nヨウ\n\nおさな\nーーーー\n央\nCenter\nオウ\n\nーーーー\n冊\nTome\nサツ\nサク\n\nーーーー\n汗\nSweat\nカン\n\nあせ\nーーーー\n灯\nLamp\nトウ\n\nひ\nーーーー\n竹\nBamboo\nチク\n\nたけ\nーーーー\n糸\nThread\nシ\n\nいと\nーーーー\n州\nState\nシュウ\n\nす\nーーーー\n宇\nEaves\nウ\n\nーーーー\n灰\nAshes\nカイ\n\nはい\nーーーー\n汚\nDirty\nオ\n\nきたな\nけが\nよご\nーーーー\n羽\nFeathers\nウ\n\nはね\nば\nーーーー\n印\nStamp\nイン\n\nしるし\nーーーー\n叫\nShout\nキョウ\n\nさけ\nーーーー\n衣\nGarment\nイ\n\nころも\nーーーー\n兆\nPortent\nチョウ\n\nきざ\nーーーー\n寺\nBuddhist temple\nジ\n\nてら\nーーーー\n虫\nInsect\nチュウ\n\nむし\nーーーー\n各\nEach\nカク\n\nおのおの\nーーーー\n#\n"},
    {1, L"#"}
};

std::map<int,std::wstring> FuckWindows::wordsForWindows = {
    {5, L"十一月\nじゅういちがつ\nNovember\nーーーー\n十一\nじゅういち\n11\nーーーー\n一生\nいっしょう\nWhole life\nーーーー\n一つ\nひとつ\nOne\nーーーー\n十八\nじゅうはち\n18\nーーーー\n八月\nはちがつ\nAugust\nーーーー\n八十\nはちじゅう\nEighty\nーーーー\n百八\nひゃくはち\n108\nーーーー\n八つ\nやっつ\nEight\nーーーー\n白人\nはくじん\nWhite person\nーーーー\n本人\nほんにん\nThe person himself\nーーーー\n名人\nめいじん\nMaster\nーーーー\n人生\nじんせい\nLife\nーーーー\n十二月\nじゅうにがつ\nDecember\nーーーー\n十二\nじゅうに\n12\nーーーー\n二百\nにひゃく\nTwo hundred\nーーーー\n二月\nにがつ\nFebruary\nーーーー\n二つ\nふたつ\nTwo\nーーーー\n入学\nにゅうがく\nEntry to school or university\nーーーー\n入手\nにゅうしゅ\nAcquisition\nーーーー\n出入\nしゅつにゅう\nIn and out\nーーーー\n入金\nにゅうきん\nDeposit\nーーーー\n入れる\nいれる\nTo put in\nーーーー\n入る\nはいる\nTo enter\nーーーー\n十月\nじゅうがつ\nOctober\nーーーー\n十四\nじゅうよん\n14\nーーーー\n十五\nじゅうご\n15\nーーーー\n十七\nじゅうなな\n17\nーーーー\n七月\nしちがつ\nJuly\nーーーー\n七十\nしちじゅう\nSeventy\nーーーー\n七つ\nななつ\nSeven\nーーーー\n十九\nじゅうきゅう\n19\nーーーー\n九月\nくがつ\nSeptember\nーーーー\n九十\nきゅうじゅう\nNinety\nーーーー\n九つ\nここのつ\nNine\nーーーー\n小学生\nしょうがくせい\nElementary school student\nーーーー\n小学\nしょうがく\nElementary school\nーーーー\n大小\nだいしょう\nSizes\nーーーー\n中小\nちゅうしょう\nSmall to medium\nーーーー\n小さい\nちいさい\nSmall\nーーーー\n上空\nじょうくう\nSky\nーーーー\n水上\nすいじょう\nAquatic\nーーーー\n上田\nじょうでん\nHigh rice field\nーーーー\n路上\nろじょう\nRoad\nーーーー\n上\nうえ\nAbove\nーーーー\n川上\nかわかみ\nUpstream\nーーーー\n上げる\nあげる\nTo raise\nーーーー\n上がる\nあがる\nTo rise\nーーーー\n上る\nのぼる\nTo ascend\nーーーー\n山下\nさんげ\nFoot of a mountain\nーーーー\n下車\nげしゃ\nGetting off\nーーーー\n天下\nてんか\nThe whole world\nーーーー\n下水\nげすい\nDrainage\nーーーー\n下\nした\nBelow\nーーーー\n下げる\nさげる\nTo hang\nーーーー\n下る\nくだる\nTo descend\nーーーー\n下りる\nおりる\nTo descend\nーーーー\n山川\nさんせん\nMountains and rivers\nーーーー\n大川\nたいせん\nBig river\nーーーー\n河川\nかせん\nRivers\nーーーー\n川柳\nせんりゅう\nHumorous poem\nーーーー\n#"},
    {4, L"#"},
    {3, L"#"},
    {2, L"#"},
    {1, L"#"}
};

std::map<int,std::wstring> FuckWindows::strokesForWindows = {
    {5, L"一\n-92,6;-80,4;-71,3;-57,0;-42,-2;-29,-2;-16,-3;-7,-4;1,-4;12,-5;23,-6;33,-6;41,-6;52,-5;63,-6;72,-5;81,-4;87,-3;89,-1;\n\n八\n-48,-32;-49,-27;-52,-15;-56,-3;-59,4;-64,10;-70,18;-76,25;-83,33;-88,38;-94,42;\n2,-58;8,-48;14,-35;23,-23;32,-10;39,-2;45,6;51,11;56,17;62,22;69,27;76,32;84,35;90,39;95,41;101,44;\n\n人\n-6,-80;-7,-74;-7,-67;-8,-57;-9,-50;-9,-42;-11,-33;-14,-23;-18,-13;-22,-3;-25,6;-32,18;-39,30;-47,43;-55,53;-64,63;-74,72;-79,76;-87,83;-90,85;\n-20,-4;-15,5;-6,17;2,27;10,37;21,47;34,56;46,64;57,69;67,74;78,79;84,82;85,80;\n\n#"},
    {4, L"#"},
    {3, L"#"},
    {2, L"#"},
    {1, L"#"},
};
