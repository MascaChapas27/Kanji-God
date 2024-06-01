#include "FuckWindows.hpp"

std::map<int, std::wstring> FuckWindows::kanjisForWindows = {
    {5, L"一\nOne\nイチ\nイツ\n\nひと\nーーーー\n八\nEight\nハチ\n\nや\nやっ\nーーーー\n人\nPerson\nジン\nニン\n\nひと\nーーーー\n二\nTwo\nニ\n\nふた\nーーーー\n入\nEnter\nニュウ\n\nい\nはい\nーーーー\n十\nTen\nジュウ\nジッ\n\nと\nとお\nーーーー\n七\nSeven\nシチ\n\nなな\nーーーー\n九\nNine\nキュウ\nク\n\nここの\nーーーー\n小\nSmall\nショウ\n\nお\nこ\nちい\nーーーー\n上\nUp\nジョウ\n\nあ\nうえ\nかみ\nのぼ\nーーーー\n下\nBelow\nカ\nゲ\n\nお\nくだ\nさ\nした\nしも\nもと\nーーーー\n川\nRiver\nセン\n\nかわ\nーーーー\n三\nThree\nサン\n\nみ\nみっ\nーーーー\n山\nMountain\nサン\n\nやま\nーーーー\n口\nMouth\nコウ\nク\n\nくち\nーーーー\n土\nSoil\nド\nト\n\nつち\nーーーー\n千\nThousand\nセン\n\nち\nーーーー\n大\nLarge\nダイ\nタイ\n\nおお\nーーーー\n子\nChild\nシ\nス\n\nこ\nーーーー\n万\nTen thousand\nマン\nバン\n\nーーーー\n女\nWoman\nジョ\nニョ\n\nおんな\nめ\nーーーー\n六\nSix\nロク\n\nむ\nむっ\nーーーー\n少\nFew\nショウ\n\nすく\nすこ\nーーーー\n火\nFire\nカ\n\nひ\nーーーー\n父\nFather\nフ\n\nちち\nーーーー\n今\nNow\nコン\nキン\n\nいま\nーーーー\n水\nWater\nスイ\n\nみず\nーーーー\n午\nNoon\nゴ\n\nーーーー\n分\nPart, minute of time\nブン\nブ\nフン\n\nわ\nーーーー\n手\nHand\nシュ\n\nて\nーーーー\n天\nHeaven\nテン\n\nあめ\nーーーー\n日\nDay\nニチ\nジツ\n\nか\nひ\nーーーー\n木\nTree\nボク\nモク\n\nき\nーーーー\n中\nMiddle\nチュウ\n\nなか\nーーーー\n月\nMonth, moon\nゲツ\nガツ\n\nつき\nーーーー\n五\nFive\nゴ\n\nいつ\nーーーー\n友\nFriend\nユウ\n\nとも\nーーーー\n円\nRound, yen\nエン\n\nまる\nーーーー\n立\nStand up\nリツ\n\nた\nーーーー\n北\nNorth\nホク\n\nきた\nーーーー\n半\nHalf\nハン\n\nなか\nーーーー\n外\nOutside\nガイ\nゲ\n\nそと\nはず\nほか\nーーーー\n右\nRight (direction)\nウ\nユウ\n\nみぎ\nーーーー\n出\nExit\nシュツ\n\nだ\nで\nーーーー\n古\nOld\nコ\n\nふる\nーーーー\n生\nLife\nセイ\nショウ\n\nい\nう\nお\nき\nなま\nは\nーーーー\n左\nLeft (direction)\nサ\n\nひだり\nーーーー\n四\nFour\nシ\n\nよ\nよっ\nよん\nーーーー\n本\nBook\nホン\n\nもと\nーーーー\n白\nWhite\nハク\nビャク\n\nしろ\nーーーー\n目\nEye\nモク\n\nめ\nーーーー\n母\nMother\nボ\n\nはは\nーーーー\n行\nGo\nコウ\nギョウ\n\nい\nおこな\nゆ\nーーーー\n多\nMany\nタ\n\nおお\nーーーー\n名\nName\nメイ\nミョウ\n\nな\nーーーー\n年\nYear\nネン\n\nとし\nーーーー\n会\nMeeting\nカイ\nエ\n\nあ\nーーーー\n先\nPrevious\nセン\n\nさき\nーーーー\n耳\nEar\nジ\n\nみみ\nーーーー\n百\nHundred\nヒャク\n\nーーーー\n気\nFeeling\nキ\nケ\n\nーーーー\n休\nRest\nキュウ\n\nやす\nーーーー\n安\nCheap\nアン\n\nやす\nーーーー\n西\nWest\nセイ\nサイ\n\nにし\nーーーー\n毎\nEvery\nマイ\n\nーーーー\n言\nSay\nゲン\nゴン\n\nい\nこと\nーーーー\n足\nFoot\nソク\n\nあし\nた\nーーーー\n社\nCompany\nシャ\n\nやしろ\nーーーー\n花\nFlower\nカ\n\nはな\nーーーー\n何\nWhat\nカ\n\nなに\nーーーー\n来\nCome\nライ\n\nきた\nく\nーーーー\n見\nSee\nケン\n\nみ\nーーーー\n車\nCar\nシャ\n\nくるま\nーーーー\n男\nMale\nダン\nナン\n\nおとこ\nーーーー\n学\nStudy\nガク\n\nまな\nーーーー\n空\nSky\nクウ\n\nあ\nから\nす\nそら\nーーーー\n店\nShop\nテン\n\nみせ\nーーーー\n金\nGold\nキン\nコン\n\nかね\nーーーー\n雨\nRain\nウ\n\nあめ\nーーーー\n長\nLong\nチョウ\n\nなが\nーーーー\n東\nEast\nトウ\n\nひがし\nーーーー\n国\nCountry\nコク\n\nくに\nーーーー\n食\nEat, meal\nショク\n\nく\nた\nーーーー\n前\nIn front\nゼン\n\nまえ\nーーーー\n後\nBehind\nゴ\nコウ\n\nあと\nうし\nおく\nのち\nーーーー\n南\nSouth\nナン\n\nみなみ\nーーーー\n校\nSchool\nコウ\n\nーーーー\n時\nTime\nジ\n\nとき\nーーーー\n高\nTall, expensive\nコウ\n\nたか\nーーーー\n書\nWrite\nショ\n\nか\nーーーー\n魚\nFish\nギョ\n\nうお\nさかな\nーーーー\n週\nWeek\nシュウ\n\nーーーー\n飲\nDrink\nイン\n\nの\nーーーー\n道\nRoad\nドウ\n\nみち\nーーーー\n買\nBuy\nバイ\n\nか\nーーーー\n間\nInterval\nカン\nケン\n\nあいだ\nま\nーーーー\n話\nTalk\nワ\n\nはな\nはなし\nーーーー\n新\nNew\nシン\n\nあたら\nあら\nにい\nーーーー\n電\nElectricity\nデン\n\nーーーー\n読\nRead\nドク\nトク\n\nよ\nーーーー\n語\nLanguage\nゴ\n\nかた\nーーーー\n駅\nStation\nエキ\n\nーーーー\n聞\nHear\nブン\nモン\n\nき\nーーーー\n#"},
    {4, L"#"},
    {3, L"#"},
    {2, L"#"},
    {1, L"#"}
};

std::map<int,std::wstring> FuckWindows::wordsForWindows = {
    {5, L"十一月\nじゅういちがつ\nNovember\nーーーー\n十一\nじゅういち\n11\nーーーー\n一生\nいっしょう\nWhole life\nーーーー\n一つ\nひとつ\nOne\nーーーー\n十八\nじゅうはち\n18\nーーーー\n八月\nはちがつ\nAugust\nーーーー\n八十\nはちじゅう\nEighty\nーーーー\n百八\nひゃくはち\n108\nーーーー\n八つ\nやっつ\nEight\nーーーー\n白人\nはくじん\nWhite person\nーーーー\n本人\nほんにん\nThe person himself\nーーーー\n名人\nめいじん\nMaster\nーーーー\n人生\nじんせい\nLife\nーーーー\n十二月\nじゅうにがつ\nDecember\nーーーー\n十二\nじゅうに\n12\nーーーー\n二百\nにひゃく\nTwo hundred\nーーーー\n二月\nにがつ\nFebruary\nーーーー\n二つ\nふたつ\nTwo\nーーーー\n入学\nにゅうがく\nEntry to school or university\nーーーー\n入手\nにゅうしゅ\nAcquisition\nーーーー\n出入\nしゅつにゅう\nIn and out\nーーーー\n入金\nにゅうきん\nDeposit\nーーーー\n入れる\nいれる\nTo put in\nーーーー\n入る\nはいる\nTo enter\nーーーー\n十月\nじゅうがつ\nOctober\nーーーー\n十四\nじゅうよん\n14\nーーーー\n十五\nじゅうご\n15\nーーーー\n十七\nじゅうなな\n17\nーーーー\n七月\nしちがつ\nJuly\nーーーー\n七十\nしちじゅう\nSeventy\nーーーー\n七つ\nななつ\nSeven\nーーーー\n十九\nじゅうきゅう\n19\nーーーー\n九月\nくがつ\nSeptember\nーーーー\n九十\nきゅうじゅう\nNinety\nーーーー\n九つ\nここのつ\nNine\nーーーー\n小学生\nしょうがくせい\nElementary school student\nーーーー\n小学\nしょうがく\nElementary school\nーーーー\n大小\nだいしょう\nSizes\nーーーー\n中小\nちゅうしょう\nSmall to medium\nーーーー\n小さい\nちいさい\nSmall\nーーーー\n上空\nじょうくう\nSky\nーーーー\n水上\nすいじょう\nAquatic\nーーーー\n上\nうえ\nUp\nーーーー\n川上\nかわかみ\nUpstream\nーーーー\n上げる\nあげる\nTo raise\nーーーー\n上がる\nあがる\nTo rise\nーーーー\n上る\nのぼる\nTo ascend\nーーーー\n山下\nさんげ\nFoot of a mountain\nーーーー\n下車\nげしゃ\nGetting off\nーーーー\n天下\nてんか\nThe whole world\nーーーー\n下水\nげすい\nDrainage\nーーーー\n下\nした\nBelow\nーーーー\n下げる\nさげる\nTo hang\nーーーー\n下る\nくだる\nTo descend\nーーーー\n下りる\nおりる\nTo descend\nーーーー\n山川\nさんせん\nMountains and rivers\nーーーー\n大川\nたいせん\nBig river\nーーーー\n川柳\nせんりゅう\nHumorous poem\nーーーー\n十三\nじゅうさん\n13\nーーーー\n三月\nさんがつ\nMarch\nーーーー\n三十\nさんじゅう\nThirty\nーーーー\n三人\nさんにん\nThree people\nーーーー\n三つ\nみっつ\nThree\nーーーー\n山中\nさんちゅう\nIn the mountains\nーーーー\n人口\nじんこう\nPopulation\nーーーー\n口上\nこうじょう\nVocal message\nーーーー\n本土\nほんど\nMainland\nーーーー\n土木\nどぼく\nEngineering works\nーーーー\n出土\nしゅつど\nArcheological excavation\nーーーー\n土\nつち\nEarth\nーーーー\n一千\nいっせん\n1000\nーーーー\n千里\nせんり\n1000 ri\nーーーー\n女子大\nじょしだい\nWomen's college\nーーーー\n大気\nたいき\nAtmosphere\nーーーー\n大学\nだいがく\nUniversity\nーーーー\n大きい\nおおきい\nBig\nーーーー\n金子\nきんす\nMoney\nーーーー\n男子\nだんし\nYoung man\nーーーー\n女子\nじょし\nGirl\nーーーー\n百万\nひゃくまん\n1000000\nーーーー\n十万\nじゅうまん\n100000\nーーーー\n五百万\nごひゃくまん\n5000000\nーーーー\n一万\nいちまん\n10000\nーーーー\n男女\nだんじょ\nMen and women\nーーーー\n女\nおんな\nFemale\nーーーー\n六月\nろくがつ\nJune\nーーーー\n六十\nろくじゅう\nSixty\nーーーー\n十六\nじゅうろく\n16\nーーーー\n四六時中\nしろくじちゅう\nAround the clock\nーーーー\n六つ\nむっつ\nSix\nーーーー\n少年\nしょうねん\nBoy\nーーーー\n少女\nしょうじょ\nLittle girl\nーーーー\n多少\nたしょう\nMore or less\nーーーー\n少ない\nすくない\nFew\nーーーー\n少し\nすこし\nSmall quantity\nーーーー\n出火\nしゅっか\nOutbreak of fire\nーーーー\n大火\nたいか\nLarge fire\nーーーー\n火災\nかさい\nConflagration\nーーーー\n父母\nふぼ\nFather and mother\nーーーー\n父子\nふし\nFather and child\nーーーー\n義父\nぎふ\nFather-in-law\nーーーー\n今週\nこんしゅう\nThis week\nーーーー\n今後\nこんご\nFrom now on\nーーーー\n水中\nすいちゅう\nUnderwater\nーーーー\n午後\nごご\nAfternoon\nーーーー\n午前\nごぜん\nMorning\nーーーー\n半分\nはんぶん\nHalf\nーーーー\n気分\nきぶん\nFeeling\nーーーー\n分ける\nわける\nTo divide\nーーーー\n分かれる\nわかれる\nTo branch\nーーーー\n分かる\nわかる\nTo understand\nーーーー\n手中\nしゅちゅう\nIn one's hands\nーーーー\n名手\nめいしゅ\nMaster\nーーーー\n天気\nてんき\nWeather\nーーーー\n天\nあめ\nSky\nーーーー\n先日\nせんじつ\nThe other day\nーーーー\n休日\nきゅうじつ\nHoliday\nーーーー\n一日\nいちにち\nOne day\nーーーー\n中日\nちゅうにち\nChina and japan\nーーーー\n日\nひ/か\nDay/Day of month\nーーーー\n大木\nたいぼく\nLarge tree\nーーーー\n高木\nこうぼく\nTall tree\nーーーー\n中立\nちゅうりつ\nNeutrality\nーーーー\n中学生\nちゅうがくせい\nJunior high school student\nーーーー\n中学\nちゅうがく\nMiddle school\nーーーー\n空中\nくうちゅう\nSky\nーーーー\n中\nなか\nInside\nーーーー\n四月\nしがつ\nApril\nーーーー\n月\nつき\nMoon\nーーーー\n五百\nごひゃく\n500\nーーーー\n五十\nごじゅう\nFifty\nーーーー\n五つ\nいつつ\nFive\nーーーー\n友人\nゆうじん\nFriend\nーーーー\n一円\nいちえん\nOne yen\nーーーー\n円滑\nえんかつ\nSmooth\nーーーー\n円い\nまるい\nRound\nーーーー\n立つ\nたつ\nTo stand\nーーーー\n立てる\nたてる\nTo stand up\nーーーー\n東北\nとうほく\nNorth-east\nーーーー\n北東\nほくとう\nNortheast\nーーーー\n北西\nほくせい\nNorthwest\nーーーー\n時半\nじはん\nHalf an hour\nーーーー\n後半\nこうはん\nSecond half\nーーーー\n半ば\nなかば\nMiddle\nーーーー\n外国\nがいこく\nForeign country\nーーーー\n国外\nこくがい\nOutside the country\nーーーー\n外\nそと/ほか\nOutside/Other\nーーーー\n外す\nはずす\nTo unfasten\nーーーー\n外れる\nはずれる\nTo be disconnected\nーーーー\n左右\nさゆう\nLeft and right\nーーーー\n右翼\nうよく\nRight-wing\nーーーー\n右中間\nうちゅうかん\nBetween right and center fielders\nーーーー\n出生\nしゅっしょう\nBirth\nーーーー\n出る\nでる\nTo leave\nーーーー\n出す\nだす\nTo take out\nーーーー\n古書\nこしょ\nOld book\nーーーー\n中古車\nちゅうこしゃ\nUsed car\nーーーー\n中古\nちゅうこ\nUsed\nーーーー\n古い\nふるい\nOld\nーーーー\n古す\nふるす\nTo wear out\nーーーー\n年生\nねんせい\nPupil in ... year\nーーーー\n学生\nがくせい\nStudent\nーーーー\n生きる\nいきる\nTo live\nーーーー\n生ける\nいける\nTo arrange flowers\nーーーー\n生まれる\nうまれる\nTo be born\nーーーー\n生む\nうむ\nTo give birth\nーーーー\n生える\nはえる\nTo sprout\nーーーー\n生\nなま\nRaw\nーーーー\n左翼\nさよく\nLeft-wing\nーーーー\n左派\nさは\nLeft wing\nーーーー\n四つ\nよっつ\nFour\nーーーー\n本名\nほんみょう\nReal name\nーーーー\n本気\nほんき\nSeriousness\nーーーー\n空白\nくうはく\nWhite space\nーーーー\n白書\nはくしょ\nWhite paper\nーーーー\n白日\nはくじつ\nBright sunshine\nーーーー\n白い\nしろい\nWhite\nーーーー\n名目\nめいもく\nName\nーーーー\n項目\nこうもく\nItem\nーーーー\n母国\nぼこく\nOne's homeland\nーーーー\n空母\nくうぼ\nAircraft carrier\nーーーー\n母\nはは\nMother\nーーーー\n先行\nせんこう\nPreceding\nーーーー\n行く\nいく\nTo go\nーーーー\n行う\nおこなう\nTo perform\nーーーー\n多分\nたぶん\nPerhaps\nーーーー\n多い\nおおい\nMany\nーーーー\n大名\nだいみょう\nJapanese feudal lord\nーーーー\n年金\nねんきん\nAnnuity\nーーーー\n学年\nがくねん\nAcademic year\nーーーー\n社会\nしゃかい\nSociety\nーーーー\n会長\nかいちょう\nPresident\nーーーー\n会話\nかいわ\nConversation\nーーーー\n会う\nあう\nTo meet\nーーーー\n先生\nせんせい\nTeacher\nーーーー\n先月\nせんげつ\nLast month\nーーーー\n先見\nせんけん\nForesight\nーーーー\n先\nさき\nPrevious\nーーーー\n耳目\nじもく\nEye and ear\nーーーー\n中耳\nちゅうじ\nMiddle ear\nーーーー\n中耳炎\nちゅうじえん\nInflammation of the middle ear\nーーーー\n九百\nくひゃく\n900\nーーーー\n七百\nしちひゃく\n700\nーーーー\n空気\nくうき\nAir\nーーーー\n人気\nにんき\nPopularity\nーーーー\n休暇\nきゅうか\nDay off\nーーーー\n年休\nねんきゅう\nYearly paid vacation\nーーーー\n休校\nきゅうこう\nClosing school\nーーーー\n休む\nやすむ\nTo be absent\nーーーー\n休まる\nやすまる\nTo be rested\nーーーー\n休める\nやすめる\nTo rest\nーーーー\n安い\nやすい\nCheap\nーーーー\n南西\nなんせい\nSouthwest\nーーーー\n毎週\nまいしゅう\nEvery week\nーーーー\n毎月\nまいつき\nEvery month\nーーーー\n毎日\nまいにち\nEvery day\nーーーー\n言語\nげんご\nLanguage\nーーーー\n言う\nいう\nSay\nーーーー\n言\nこと\nWord\nーーーー\n一足\nいっそく\nPair\nーーーー\n足\nあし\nFoot\nーーーー\n足りる\nたりる\nTo be sufficient\nーーーー\n足る\nたる\nTo be enough\nーーーー\n足す\nたす\nTo add\nーーーー\n社長\nしゃちょう\nCompany president\nーーーー\n社\nやしろ\nShrine\nーーーー\n花月\nかげつ\nFlowers and the moon\nーーーー\n来週\nらいしゅう\nNext week\nーーーー\n来月\nらいげつ\nNext month\nーーーー\n来日\nらいにち\nArrival in japan\nーーーー\n来る\nくる\nTo come\nーーーー\n来す\nきたす\nTo cause\nーーーー\n見学\nけんがく\nInspection\nーーーー\n一見\nいっけん\nLook\nーーーー\n見る\nみる\nTo see\nーーーー\n見える\nみえる\nTo be seen\nーーーー\n見せる\nみせる\nTo show\nーーーー\n車中\nしゃちゅう\nIn a train or vehicle\nーーーー\n電車\nでんしゃ\nTrain\nーーーー\n三男\nさんなん\nThree sons\nーーーー\n一男\nいちなん\nBoy\nーーーー\n男\nおとこ\nMan\nーーーー\n学校\nがっこう\nSchool\nーーーー\n学ぶ\nまなぶ\nTo study\nーーーー\n空\nそら\nSky\nーーーー\n空く\nあく\nTo open\nーーーー\n空ける\nあける\nTo empty\nーーーー\n書店\nしょてん\nBookshop\nーーーー\n本店\nほんてん\nHead office\nーーーー\n店長\nてんちょう\nShop manager\nーーーー\n大金\nたいきん\nLarge amount of money\nーーーー\n金\nかね\nMoney\nーーーー\n雨天\nうてん\nRainy weather\nーーーー\n雨中\nうちゅう\nIn the rain\nーーーー\n長い\nながい\nLong\nーーーー\n東南\nとうなん\nSouth-east\nーーーー\n外食\nがいしょく\nEating out\nーーーー\n食う\nくう\nTo bite\nーーーー\n食べる\nたべる\nTo eat\nーーーー\n前後\nぜんご\nFront and rear\nーーーー\n前\nまえ\nAgo\nーーーー\n後ろ\nうしろ\nBack\nーーーー\n後\nあと\nBehind\nーーーー\n後れる\nおくれる\nTo be late\nーーーー\n高校生\nこうこうせい\nSenior high school student\nーーーー\n高校\nこうこう\nSenior high school\nーーーー\n校長\nこうちょう\nPrincipal\nーーーー\n時間\nじかん\nTime\nーーーー\n高い\nたかい\nHigh\nーーーー\n高まる\nたかまる\nTo rise\nーーーー\n高める\nたかめる\nTo enhance\nーーーー\n読書\nどくしょ\nReading\nーーーー\n書く\nかく\nTo write\nーーーー\n金魚\nきんぎょ\nGoldfish\nーーーー\n魚\nさかな\nFish\nーーーー\n先週\nせんしゅう\nLast week\nーーーー\n飲食\nいんしょく\nFood and drink\nーーーー\n飲む\nのむ\nTo drink\nーーーー\n水道\nすいどう\nWater service\nーーーー\n人道\nじんどう\nHumanity\nーーーー\n書道\nしょどう\nCalligraphy\nーーーー\n道\nみち\nRoad\nーーーー\n購買\nこうばい\nProcurement\nーーーー\n買う\nかう\nTo buy\nーーーー\n空間\nくうかん\nSpace\nーーーー\n年間\nねんかん\nYears\nーーーー\n間\nあいだ\nSpace\nーーーー\n電話\nでんわ\nTelephone call\nーーーー\n話す\nはなす\nTo talk\nーーーー\n話\nはなし\nTalk\nーーーー\n新聞社\nしんぶんしゃ\nNewspaper company\nーーーー\n新聞\nしんぶん\nNewspaper\nーーーー\n新しい\nあたらしい\nNew\nーーーー\n新た\nあらた\nNew\nーーーー\n電気\nでんき\nElectricity\nーーーー\n朗読\nろうどく\nReading aloud\nーーーー\n読本\nとくほん\nReading-book\nーーーー\n読む\nよむ\nTo read\nーーーー\n外国語\nがいこくご\nForeign language\nーーーー\n国語\nこくご\nNational language\nーーーー\n語る\nかたる\nTo talk about\nーーーー\n語らう\nかたらう\nTo talk\nーーーー\n見聞\nけんぶん\nInformation\nーーーー\n聞く\nきく\nTo hear\nーーーー\n聞こえる\nきこえる\nTo be heard\nーーーー\n#"},
    {4, L"#"},
    {3, L"#"},
    {2, L"#"},
    {1, L"#"}
};

std::map<int,std::wstring> FuckWindows::strokesForWindows = {
    {5, L"一\n-92,6;-80,4;-71,3;-57,0;-42,-2;-29,-2;-16,-3;-7,-4;1,-4;12,-5;23,-6;33,-6;41,-6;52,-5;63,-6;72,-5;81,-4;87,-3;89,-1;\n\n八\n-48,-32;-49,-27;-52,-15;-56,-3;-59,4;-64,10;-70,18;-76,25;-83,33;-88,38;-94,42;\n2,-58;8,-48;14,-35;23,-23;32,-10;39,-2;45,6;51,11;56,17;62,22;69,27;76,32;84,35;90,39;95,41;101,44;\n\n人\n-6,-80;-7,-74;-7,-67;-8,-57;-9,-50;-9,-42;-11,-33;-14,-23;-18,-13;-22,-3;-25,6;-32,18;-39,30;-47,43;-55,53;-64,63;-74,72;-79,76;-87,83;-90,85;\n-20,-4;-15,5;-6,17;2,27;10,37;21,47;34,56;46,64;57,69;67,74;78,79;84,82;85,80;\n\n二\n-54,-51;-49,-49;-40,-48;-26,-47;-9,-48;4,-49;15,-51;29,-54;37,-56;45,-58;\n-94,56;-88,54;-79,52;-70,51;-59,50;-50,50;-41,49;-29,49;-18,49;-7,49;3,50;17,49;28,49;40,49;49,50;59,50;71,52;83,54;90,55;98,56;101,57;\n\n入\n-10,-22;-24,4;-78,63;-93,73;\n-56,-75;-49,-69;-33,-55;-16,-36;1,-14;17,3;36,22;61,45;105,70;\n\n十\n-76,-2;-46,-4;23,-10;95,-12;\n-2,-100;-3,-55;-3,67;-3,104;\n\n七\n-98,7;-90,8;-72,6;-47,2;-14,-6;25,-14;62,-20;94,-23;97,-21;\n-33,-80;-34,-70;-35,-53;-37,-33;-37,-21;-37,-7;-37,3;-37,14;-37,24;-35,34;-32,41;-27,52;-23,56;-19,61;-15,64;-11,69;-3,72;5,75;14,77;26,79;37,78;46,78;57,76;\n\n九\n-19,-89;-20,-67;-30,-24;-61,32;-94,69;\n-76,-32;-70,-33;-55,-35;-23,-42;11,-48;34,-52;32,-48;25,-37;17,-14;12,9;8,27;5,42;5,55;7,60;11,67;17,72;28,74;40,75;57,76;79,72;88,69;92,69;85,53;\n\n小\n-5,-95;-2,-79;-1,-52;0,-27;0,-3;0,17;-1,35;-2,55;-3,69;-3,80;-6,89;-8,89;-17,70;\n-58,-15;-62,-4;-77,20;-103,39;\n53,-24;67,-12;85,10;97,34;\n\n上\n-14,-85;-12,-65;-11,-30;-11,8;-16,51;-17,66;\n-12,-13;-2,-15;33,-21;54,-25;\n-91,76;-83,73;-71,72;-56,70;-37,69;-11,68;13,66;38,66;64,66;97,68;\n\n下\n-87,-73;-75,-72;-49,-75;-7,-78;40,-79;80,-79;\n-4,-82;-3,-43;-4,27;-8,84;\n-4,-51;43,-23;\n\n川\n-56,-56;-54,-37;-59,9;-78,49;\n7,-60;8,-16;8,27;\n82,-79;83,-30;81,72;\n\n三\n-62,-68;-56,-68;-41,-68;-1,-72;43,-80;\n-55,-3;-48,-1;-18,-1;25,-5;\n-95,78;-87,77;-58,72;-16,70;35,71;85,74;\n\n山\n2,-82;1,-60;2,13;-1,76;\n-69,6;-69,11;-65,49;-60,79;-57,79;-40,78;6,75;69,80;\n85,-6;76,48;68,84;\n\n口\n-78,-55;-73,-17;-67,53;\n-77,-54;-68,-56;-49,-56;-20,-60;10,-61;32,-62;41,-62;46,-62;60,-63;79,-62;85,-59;82,-45;73,17;64,55;\n-67,52;-56,51;-10,48;68,47;\n\n土\n-58,-2;-45,0;-13,-1;43,-6;\n-10,-80;-10,-53;-10,28;-12,81;\n-93,85;-79,84;-44,80;28,79;91,80;\n\n千\n34,-94;6,-78;-52,-57;\n-86,-2;-70,-2;-33,-4;44,-10;103,-12;\n0,-77;3,-12;1,88;\n\n大\n-77,-21;-63,-20;-24,-19;38,-24;79,-28;\n-12,-86;-12,-69;-12,-42;-16,-7;-31,28;-57,57;-89,80;\n-17,-17;-6,3;28,46;82,85;\n\n子\n-50,-85;-34,-86;-4,-87;24,-89;34,-89;39,-89;47,-90;44,-83;32,-68;21,-58;12,-52;7,-50;3,-48;-1,-46;\n-8,-54;-5,-51;-1,-47;4,-44;9,-37;13,-30;16,-23;18,-14;20,-3;21,8;21,18;21,32;19,43;15,57;11,66;3,78;-2,86;-6,92;-14,82;\n-86,-5;-79,-5;-64,-6;-39,-10;-3,-13;26,-16;52,-18;90,-18;\n\n万\n-77,-69;-74,-69;-61,-70;-35,-74;4,-78;52,-83;86,-83;\n-1,-40;19,-38;42,-31;53,-27;50,-12;37,24;21,60;12,75;9,80;2,74;\n8,-77;6,-57;-11,-18;-53,27;-87,53;\n\n女\n-10,-99;-12,-89;-20,-66;-27,-43;-39,-18;-47,-1;-57,15;-63,26;-66,29;-65,31;-60,31;-51,35;-37,39;-23,46;-10,52;3,59;20,67;40,77;56,87;65,95;67,98;\n32,-42;30,-31;23,-11;18,9;9,26;-1,43;-15,59;-31,71;-47,81;-61,87;-69,90;-69,91;\n-98,-24;-88,-25;-60,-29;-12,-34;46,-37;86,-35;92,-33;\n\n六\n-4,-76;-4,-41;-4,-24;\n-80,-21;-66,-20;-35,-22;21,-27;90,-32;\n-44,25;-45,33;-50,48;-64,68;-80,80;-79,82;\n43,20;54,33;78,60;93,87;\n\n少\n-5,-95;-4,-79;-3,-45;-6,-8;-7,3;-8,7;-11,8;-20,0;\n-55,-59;-60,-46;-75,-22;-97,1;\n42,-62;62,-47;91,-23;\n34,-31;29,-16;6,26;-36,71;-71,99;\n\n火\n-80,-50;-67,-33;-48,-3;\n72,-63;57,-37;30,-9;\n-11,-95;-11,-91;-10,-88;-9,-73;-11,-48;-15,-14;-25,22;-40,56;-66,84;-86,94;\n-17,5;-12,12;3,33;40,65;96,96;\n\n父\n-47,-92;-54,-71;-78,-43;-100,-26;\n31,-93;55,-75;84,-42;\n16,-43;11,-22;-8,20;-47,62;-84,83;\n-54,-33;-46,-23;-29,-4;-9,18;12,38;36,56;64,74;98,85;\n\n今\n-4,-92;-5,-89;-7,-80;-9,-75;-14,-66;-18,-58;-21,-53;-29,-41;-37,-33;-47,-22;-59,-11;-73,0;-85,9;-89,11;-93,14;\n-2,-93;2,-85;9,-73;16,-63;27,-50;35,-40;44,-31;50,-23;60,-14;68,-7;77,-1;82,3;86,6;91,8;92,9;\n-36,-7;-23,-5;-2,-5;16,-5;26,-6;33,-6;37,-6;37,-7;\n-37,23;-21,22;-3,21;22,18;31,18;40,17;37,25;26,44;6,68;-10,85;\n\n水\n-12,-96;-11,-84;-9,-60;-8,-38;-8,-12;-7,13;-8,38;-9,58;-10,72;-11,84;-13,93;-16,89;-26,74;\n-93,-25;-72,-29;-41,-36;-29,-37;-31,-32;-53,1;-91,36;\n68,-82;58,-71;30,-48;-4,-32;\n-2,-36;9,-20;32,5;58,29;87,47;\n\n午\n-37,-102;-44,-86;-67,-53;-88,-28;\n-61,-61;-41,-60;3,-62;49,-67;\n-92,6;-81,5;-51,2;-14,0;23,-4;63,-8;93,-9;\n-7,-57;-8,-45;-9,30;-11,94;\n\n分\n-38,-67;-46,-50;-74,-8;-92,12;\n-7,-86;9,-65;46,-33;95,2;\n-58,-2;-44,-3;-16,-7;12,-10;28,-10;32,-10;36,-9;34,7;29,38;21,69;16,85;12,91;8,96;-3,90;\n-25,-5;-28,13;-49,58;-71,85;\n\n手\n15,-95;-16,-72;-51,-51;\n-64,-25;-47,-26;5,-31;47,-35;\n-81,21;-58,20;0,12;65,8;\n-16,-74;-12,-63;0,-36;8,4;8,45;4,77;-1,90;-5,90;-28,76;\n\n天\n-76,-68;-66,-68;-36,-70;16,-74;64,-76;\n-65,-14;-43,-16;-6,-18;36,-20;\n-16,-73;-13,-60;-14,-33;-22,0;-38,33;-61,61;-88,78;\n-15,-16;-14,-8;-6,9;4,23;16,37;33,52;56,67;88,78;\n\n日\n-61,-71;-61,-62;-59,-42;-57,-7;-58,50;-59,77;\n-60,-72;-54,-72;-30,-75;-1,-78;34,-79;52,-80;64,-77;65,-67;66,-36;66,19;65,71;\n-54,3;-45,3;-12,-1;33,-5;67,-5;\n-58,74;-47,73;-19,70;23,68;65,70;\n\n木\n-75,-43;-66,-41;-45,-41;-12,-43;23,-44;61,-48;82,-49;\n-6,-97;-6,-60;-6,32;-6,88;\n-7,-43;-16,-21;-49,25;-85,56;\n-7,-43;0,-27;21,2;55,39;87,60;\n\n中\n-2,-92;-1,-75;-1,-22;-1,43;1,90;\n-72,-38;-68,-15;-63,36;\n-68,-35;-57,-38;-24,-41;19,-44;61,-47;71,-42;65,-14;59,28;\n-62,33;-55,33;-32,30;8,26;59,22;\n\n月\n-36,-89;-34,-74;-34,-39;-41,18;-57,72;\n-36,-89;-30,-89;-9,-92;28,-96;55,-96;54,-92;53,-72;51,-36;52,8;54,49;54,78;54,95;50,92;29,69;\n-32,-41;-19,-40;5,-43;30,-44;51,-45;\n-42,11;-35,10;-15,8;9,6;34,6;49,6\n\n五\n-57,-71;-37,-72;1,-76;40,-80;\n-11,-71;-14,-57;-21,-28;-32,8;-44,44;-56,71;\n-73,-1;-47,-4;-6,-8;17,-10;31,-10;34,-10;36,-6;37,3;30,28;17,66;\n-102,79;-96,77;-76,73;-52,69;-23,68;11,68;49,68;83,74;\n\n友\n-79,-28;-62,-29;-15,-35;47,-38;81,-39;\n-13,-91;-16,-72;-24,-37;-45,13;-68,52;-93,82;\n-36,3;-28,1;-2,-3;22,-4;27,-2;23,8;7,35;-24,67;-51,83;\n-36,2;-32,8;-18,25;5,46;35,64;60,79;89,90;\n\n円\n-64,-66;-64,-60;-64,-32;-64,15;-64,66;\n-68,-70;-62,-70;-49,-74;-29,-77;-6,-80;14,-80;32,-80;52,-80;63,-78;67,-75;68,-67;69,-40;70,-8;70,22;70,43;71,57;71,69;71,74;70,78;64,75;46,67;35,58;\n-2,-79;-3,-70;-3,-29;-3,-15;\n-64,-11;-57,-12;-41,-13;-23,-14;-1,-15;22,-15;42,-15;56,-15;66,-15;\n\n立\n-7,-85;-7,-72;-7,-52;-7,-47;\n-61,-40;-56,-40;-37,-41;-6,-44;33,-47;63,-47;\n-45,-40;-41,-3;-34,60;\n44,-48;36,4;27,63;\n-87,72;-82,72;-70,72;-47,70;-9,66;36,68;79,72;\n\n北\n-93,-11;-79,-14;-53,-22;\n-47,-64;-49,-9;-53,45;\n-101,71;-77,59;-41,35;\n63,-61;52,-50;19,-25;6,-20;\n7,-71;1,-49;-1,-19;-1,4;0,22;4,35;11,48;19,56;35,64;56,68;71,67;84,66;91,64;93,48;\n\n半\n-59,-84;-42,-58;\n58,-90;41,-69;22,-52;\n-62,-25;-48,-25;-1,-27;56,-30;\n-93,31;-74,29;-42,26;1,25;52,24;91,27;\n-8,-99;-8,-70;-7,14;-8,94;\n\n外\n-46,-81;-53,-65;-71,-33;-83,-17;\n-52,-68;-34,-71;-3,-77;6,-78;1,-60;-20,-15;-57,51;-77,76;\n-63,-26;-47,-10;-28,2;\n30,-96;30,-62;31,22;28,81;\n34,-19;67,6;82,22;\n\n右\n-4,-95;-9,-77;-19,-45;-38,-3;-59,27;-87,55;\n-79,-27;-70,-27;-38,-32;1,-35;55,-39;93,-39;\n-52,16;-48,31;-45,56;-41,86;\n-45,20;-31,18;6,12;45,8;64,9;63,18;54,47;45,83;\n-41,84;-22,83;11,80;48,79;\n\n出\n-8,-85;-7,-63;-6,6;-6,61;-6,82;\n-56,-50;-54,-37;-50,-12;-49,-4;-47,-4;-42,-4;-23,-5;5,-5;36,-6;47,-5;46,-6;\n50,-53;48,-30;46,-7;\n-72,30;-71,41;-68,63;-66,80;-65,86;-63,87;-56,86;-37,85;-12,83;28,82;62,86;\n73,25;69,51;65,84;\n\n古\n-94,-16;-77,-17;-48,-19;-3,-25;42,-30;87,-32;\n-3,-93;-3,-62;-4,-7;-2,20;-1,25;\n-65,34;-60,57;-55,94;\n-61,33;-52,32;-34,30;-1,27;37,23;61,24;70,24;70,26;67,37;61,60;53,90;\n-52,96;-43,95;-17,94;16,90;49,91;\n\n生\n-42,-75;-48,-55;-66,-23;-82,-5;\n-60,-31;-55,-27;-48,-26;-29,-25;-4,-28;22,-32;42,-35;63,-37;\n2,-83;2,-62;2,-25;-1,33;-4,83;\n-58,28;-54,27;-40,27;-11,24;26,21;48,21;\n-75,93;-65,91;-47,89;-20,88;6,87;41,87;81,86;\n\n左\n-72,-36;-67,-36;-50,-38;-21,-40;14,-42;52,-46;82,-47;\n-5,-89;-7,-74;-11,-55;-19,-25;-29,5;-43,29;-59,48;-75,63;-85,70;\n-24,24;-13,24;11,22;40,20;49,21;\n11,23;11,45;10,72;10,85;\n-51,91;-36,89;-8,87;27,85;66,88;89,92;\n\n四\n-93,-37;-91,-22;-87,9;-83,40;-80,56;\n-91,-42;-86,-42;-75,-43;-59,-43;-29,-46;1,-47;31,-47;54,-47;77,-48;92,-46;96,-45;95,-39;91,-19;85,16;76,54;\n-27,-42;-28,-29;-34,-13;-49,10;-61,26;\n12,-49;11,-41;9,-25;10,-6;18,9;38,17;54,21;\n-76,52;-69,52;-46,50;-6,49;37,48;76,48;\n\n本\n-77,-28;-69,-28;-57,-29;-32,-32;0,-35;33,-36;58,-36;\n-13,-88;-12,-67;-11,-3;-12,68;-11,93;\n-13,-32;-21,-19;-48,13;-71,36;-89,51;-85,48;\n-8,-31;-1,-18;19,2;48,26;86,47;\n-41,43;-25,43;4,42;25,44;\n\n白\n15,-94;8,-80;-21,-48;-53,-25;\n-58,-33;-53,-5;-48,44;-45,91;\n-56,-29;-39,-29;-12,-32;29,-37;59,-40;67,-40;68,-37;68,-26;65,8;55,59;48,88;\n-50,24;-35,24;-9,21;31,18;60,18;\n-43,85;-38,85;-22,84;3,83;29,83;50,83;\n\n目\n-52,-68;-50,-45;-49,-5;-47,53;-46,86;\n-52,-68;-41,-71;-13,-75;25,-80;51,-81;58,-78;58,-68;57,-34;55,18;53,78;\n-47,-15;-34,-17;-3,-19;36,-22;57,-23;\n-47,29;-33,28;-10,26;18,25;51,23;\n-46,83;-32,83;-10,79;28,78;50,78;\n\n母\n-44,-82;-46,-66;-55,-29;-69,15;-79,41;-80,46;-73,47;-55,49;-28,55;13,66;56,80;\n-45,-80;-41,-80;-24,-81;1,-83;36,-86;58,-87;62,-83;60,-76;54,-53;45,-10;36,37;25,81;21,94;18,95;12,89;\n-16,-70;0,-56;17,-46;\n-28,2;-19,11;-2,20;\n-97,-14;-87,-15;-58,-19;-17,-23;45,-23;99,-21;\n\n行\n-41,-91;-50,-81;-78,-61;\n-42,-42;-53,-24;-83,9;-96,20;\n-63,-5;-62,9;-62,36;-63,77;-62,93;\n-7,-74;5,-74;38,-78;76,-84;\n-18,-20;-1,-24;36,-29;75,-30;97,-30;\n41,-27;42,-15;43,18;44,64;42,93;41,97;24,85;\n\n多\n-23,-91;-38,-69;-57,-49;-65,-42;\n-32,-72;-7,-77;15,-79;18,-78;13,-66;-6,-36;-34,-4;-59,15;\n-35,-53;-18,-43;-8,-32;\n25,-37;14,-18;-22,22;\n11,-10;32,-12;60,-14;72,-12;68,2;47,38;13,74;-18,92;\n13,18;32,30;41,45;\n\n名\n-9,-83;-22,-66;-54,-31;-74,-13;\n-24,-61;-11,-64;16,-68;39,-71;41,-65;19,-33;-24,13;-80,58;-92,62;\n-33,-31;-12,-6;\n-25,25;-18,50;-14,89;\n-24,26;-7,24;32,20;67,19;77,19;76,26;71,50;62,87;\n-13,89;1,87;35,84;62,85;\n\n年\n-39,-100;-48,-81;-68,-57;-76,-49;\n-54,-70;-45,-69;-25,-69;14,-71;51,-77;\n-55,-20;-50,-21;-41,-20;-19,-22;15,-26;41,-29;\n-53,-20;-51,-1;-56,27;\n-100,39;-90,37;-71,35;-38,33;2,33;44,32;90,34;\n-3,-64;-3,-30;-4,42;-2,93;\n\n会\n-7,-92;-13,-77;-38,-47;-71,-16;-86,-4;\n-5,-93;6,-76;36,-48;78,-15;94,-9;\n-33,-15;-13,-14;24,-17;\n-64,34;-48,33;-11,29;31,27;56,26;\n-13,31;-16,42;-27,62;-43,82;-46,86;-42,85;-29,82;4,71;38,65;\n25,43;44,65;56,84;\n\n先\n-35,-84;-39,-70;-57,-47;-78,-27;-78,-26;\n-53,-47;-35,-47;-3,-51;45,-57;\n-3,-90;-4,-63;-6,-8;\n-81,3;-64,0;-23,-5;38,-10;78,-10;\n-26,0;-28,19;-44,50;-72,76;-90,88;\n9,-6;7,12;6,33;8,58;16,78;33,87;45,91;59,90;69,89;73,89;79,85;82,84;83,80;78,50;\n\n耳\n-71,-83;-52,-83;-9,-87;37,-89;78,-93;\n-37,-82;-35,-45;-37,22;-36,48;\n-31,-40;-19,-42;7,-44;39,-46;\n-35,-6;-21,-5;-1,-7;28,-8;41,-8;\n-75,54;-69,58;-58,57;-30,46;9,30;60,10;\n42,-87;41,-58;43,20;43,92;\n\n百\n-89,-71;-74,-71;-42,-75;5,-78;56,-80;89,-79;\n1,-77;-8,-53;-19,-33;\n-55,-29;-55,-8;-55,47;-56,87;\n-55,-30;-39,-33;-9,-36;27,-39;48,-39;53,-37;53,-30;54,-13;53,29;49,75;49,86;\n-51,29;-45,28;-18,25;12,22;48,19;\n-56,85;-45,85;-22,84;11,82;38,81;49,83;\n\n気\n-38,-98;-46,-80;-66,-51;-71,-45;\n-56,-68;-42,-69;-2,-75;36,-78;\n-48,-43;-31,-43;2,-47;33,-50;\n-63,-9;-51,-11;-25,-15;8,-19;30,-21;39,-23;44,-23;41,-21;37,-13;35,-4;33,11;35,33;41,51;51,68;67,84;76,91;77,91;79,78;80,47;\n-14,13;-23,30;-46,60;-77,85;\n-62,29;-40,39;-21,55;-15,64;\n\n休\n-49,-94;-52,-83;-59,-60;-82,-14;-100,18;-101,21;\n-78,-19;-76,15;-76,73;-76,91;\n-55,-17;-47,-18;-25,-17;17,-21;68,-25;93,-25;\n17,-95;15,-72;15,0;15,56;14,95;\n9,-21;1,-1;-24,38;-48,66;-54,74;\n18,-19;32,2;60,39;97,71;\n\n安\n-12,-88;-13,-71;-13,-54;\n-81,-49;-82,-49;-82,-27;-82,-21;\n-80,-48;-74,-48;-63,-49;-39,-52;0,-58;41,-63;70,-64;83,-64;83,-62;78,-51;70,-40;\n-14,-22;-18,-2;-32,30;-37,42;-38,47;-31,50;-9,63;15,84;\n24,4;23,16;12,41;-14,69;-36,84;\n-93,22;-89,21;-74,17;-47,11;-16,5;24,3;57,4;90,8;\n\n西\n-59,-65;-50,-64;-23,-67;19,-74;43,-76;\n-84,-2;-82,6;-77,48;-75,82;\n-79,-1;-70,-4;-41,-12;-1,-16;37,-20;60,-21;75,-18;79,-11;76,11;69,43;61,84;\n-29,-61;-29,-45;-42,7;-56,44;\n11,-66;9,-44;6,-15;7,16;12,32;29,37;55,35;\n-74,82;-68,80;-57,78;-35,75;-3,73;31,74;61,75;\n\n毎\n-31,-92;-33,-80;-50,-51;-64,-34;\n-41,-64;-35,-64;-16,-66;16,-69;47,-70;\n-43,-36;-45,-12;-56,18;-68,46;-69,50;-65,50;-54,52;-26,56;16,69;61,82;\n-45,-35;-25,-38;7,-42;44,-44;59,-41;58,-33;53,-18;43,20;29,66;22,84;18,93;16,92;9,85;\n-3,-40;-5,-18;-18,30;-28,61;\n-100,19;-89,16;-59,11;-15,5;39,5;95,7;\n\n言\n-21,-98;4,-90;28,-80;\n-69,-40;-57,-40;-21,-45;34,-50;79,-51;\n-28,-8;-5,-10;21,-12;\n-28,22;3,18;29,15;\n-36,51;-32,72;-29,95;\n-35,56;-18,52;6,47;30,48;36,50;37,52;35,68;27,94;\n-27,95;-5,93;24,92;\n\n足\n-55,-92;-51,-73;-45,-34;\n-54,-89;-46,-89;-27,-92;2,-95;26,-95;42,-96;54,-95;56,-92;52,-83;45,-61;39,-43;\n-44,-34;-36,-34;-4,-38;31,-40;41,-37;\n-7,-34;-8,-8;-11,45;-11,65;\n-9,11;6,9;35,8;\n-51,3;-55,22;-65,50;-85,79;-86,83;\n-56,37;-48,44;-29,53;0,63;47,74;93,82;\n\n社\n-68,-84;-51,-73;-37,-68;\n-98,-30;-90,-32;-68,-36;-45,-42;-30,-45;-33,-39;-48,-12;-71,22;-92,43;\n-61,5;-58,33;-58,76;-58,80;\n-56,6;-39,19;-23,24;\n-10,-4;1,-4;33,-6;76,-12;\n28,-67;28,-31;26,36;25,72;\n-23,77;-10,75;15,71;58,71;93,73;\n\n花\n-83,-59;-71,-62;-53,-64;-29,-66;8,-69;40,-70;73,-70;\n-50,-87;-47,-70;-41,-40;\n42,-92;36,-72;26,-42;\n-41,-15;-56,8;-83,45;-96,59;\n-62,23;-63,56;-63,80;-64,91;\n77,-13;65,-2;32,20;9,29;\n14,-21;13,-8;11,12;7,41;7,60;9,68;13,75;18,80;30,85;49,86;71,85;89,82;93,77;89,58;\n\n何\n-46,-84;-50,-69;-66,-36;-90,-2;-95,4;\n-73,-24;-70,-5;-69,36;-71,68;\n-34,-54;-19,-56;12,-58;58,-62;95,-64;\n-35,-24;-31,-3;-28,18;\n-34,-22;-18,-24;5,-28;15,-29;14,-20;10,1;7,16;\n-28,15;-11,12;10,10;\n56,-62;60,-45;63,5;56,65;50,89;46,89;23,71;\n\n来\n-48,-61;-43,-61;-28,-60;0,-61;41,-65;\n-51,-37;-44,-20;-42,-12;\n47,-48;28,-22;16,-12;\n-73,7;-71,6;-55,4;-26,2;25,0;72,2;\n-4,-93;-4,-70;-5,-7;-5,46;-5,84;\n-5,3;-9,11;-17,26;-27,39;-39,53;-56,66;-72,74;\n-5,-2;1,9;10,23;26,41;41,52;58,64;70,69;85,73;\n\n見\n-39,-83;-37,-59;-33,-7;-33,14;\n-39,-84;-20,-89;4,-92;25,-93;34,-88;35,-76;35,-54;33,-14;31,11;\n-35,-53;-9,-56;34,-58;\n-34,-21;-4,-24;35,-26;\n-32,13;-5,9;30,9;\n-16,11;-17,21;-22,37;-33,56;-49,72;-66,82;\n15,11;12,15;9,25;7,36;6,46;8,56;9,63;14,69;22,74;31,77;43,79;57,81;70,80;80,79;83,79;84,61;\n\n車\n-47,-58;-37,-57;-3,-61;47,-67;\n-54,-26;-51,-16;-45,21;\n-55,-28;-46,-28;-23,-30;7,-33;40,-35;57,-35;56,-30;55,-12;49,19;\n-48,-6;-37,-8;-11,-10;19,-11;55,-10;\n-45,17;-15,18;45,16;\n-77,51;-60,50;-33,47;19,44;76,46;\n0,-93;-2,-57;-3,44;-1,88;\n\n男\n-54,-90;-48,-65;-42,-19;\n-53,-85;-46,-87;-29,-88;-7,-91;21,-93;47,-93;64,-92;67,-87;65,-75;56,-48;44,-16;\n3,-93;2,-58;1,-18;\n-46,-50;-31,-53;7,-57;53,-60;\n-39,-17;-20,-18;19,-21;48,-23;\n-53,17;-41,18;-11,18;21,16;48,12;51,13;50,17;47,36;40,64;29,81;21,82;13,71;\n-2,-15;-10,11;-33,51;-60,79;\n\n学\n-48,-82;-38,-63;\n-15,-85;-11,-74;-9,-68;\n38,-93;34,-82;20,-64;\n-83,-46;-84,-26;\n-80,-46;-64,-48;-25,-52;31,-57;76,-60;78,-51;62,-37;\n-36,-28;-27,-29;0,-33;26,-37;16,-27;-8,-4;\n-8,-6;6,14;10,57;-2,90;-7,95;-15,93;-35,81;\n-73,22;-69,22;-53,19;-18,13;23,9;71,11;\n\n空\n-6,-87;-9,-62;\n-69,-51;-68,-39;-69,-16;\n-66,-50;-50,-50;-13,-53;40,-58;76,-61;83,-62;77,-54;55,-33;\n-30,-29;-40,-6;-55,11;\n12,-37;11,-30;11,-16;14,-3;19,4;39,10;61,8;\n-42,37;-28,37;18,29;\n-11,35;-11,55;-15,82;\n-67,83;-59,82;-42,80;-10,76;24,77;56,80;\n\n店\n-1,-97;-1,-77;-2,-59;\n-59,-54;-48,-55;-22,-56;26,-61;69,-64;\n-61,-59;-60,-41;-60,-7;-70,38;-79,61;\n-1,-43;1,-21;0,25;\n1,-7;9,-8;32,-10;51,-12;\n-39,33;-33,61;-30,83;\n-36,32;-23,29;9,29;35,29;48,30;51,32;51,38;48,52;42,75;\n-27,79;-23,80;-8,80;23,79;45,78;\n\n金\n-7,-87;-13,-76;-40,-43;-85,-4;\n-5,-89;1,-78;20,-56;44,-35;68,-16;82,-11;\n-37,-17;-32,-18;-7,-18;32,-23;\n-54,20;-46,20;-31,17;-4,15;30,13;52,16;\n-4,-20;-4,16;-3,75;\n-50,41;-43,49;-37,62;\n36,32;18,60;\n-63,79;-61,79;-54,78;-40,77;-18,75;12,74;39,74;67,77;\n\n雨\n-50,-65;-33,-66;-4,-70;44,-76;\n-77,-11;-73,6;-67,57;\n-74,-11;-63,-13;-41,-17;-9,-19;26,-22;54,-25;75,-25;82,-23;79,-16;76,2;68,31;62,51;58,62;56,63;43,56;\n-6,-64;-3,-38;-3,21;-4,64;\n-46,3;-28,13;\n-51,31;-34,40;\n22,-4;36,9;\n14,27;33,38;\n\n長\n-42,-87;-41,-71;-40,-35;-40,0;\n-40,-86;-11,-89;32,-91;\n-41,-56;-30,-57;-5,-58;26,-58;\n-39,-31;-34,-32;-12,-34;22,-36;\n-89,8;-81,6;-58,1;-22,-3;18,-6;62,-5;\n-45,3;-46,22;-48,53;-49,78;-49,82;-40,75;-18,56;\n49,3;32,15;10,32;\n-14,13;6,30;46,55;82,75;\n\n東\n-47,-58;-41,-58;-19,-58;16,-61;42,-65;\n-55,-24;-50,-3;-44,21;\n-55,-24;-45,-26;-16,-30;19,-32;44,-33;48,-31;45,-18;37,13;\n-49,-3;-33,-6;0,-11;38,-12;\n-44,17;-35,15;-10,11;30,8;\n-8,-99;-8,-67;-8,4;-11,78;\n-12,16;-23,33;-48,59;-76,76;\n-6,12;0,20;14,35;46,58;83,74;\n\n国\n-69,-72;-66,-30;-65,54;-63,80;\n-65,-71;-53,-75;-29,-78;8,-79;43,-81;64,-80;70,-73;70,-48;70,10;67,73;\n-35,-41;-21,-41;11,-45;39,-50;\n-5,-41;-4,-12;-4,29;\n-39,-1;-29,-2;-4,-4;33,-8;\n-42,36;-25,33;11,30;54,31;\n16,3;33,16;\n-63,78;-50,76;-34,73;-5,71;28,71;65,73;\n\n食\n-10,-89;-28,-60;-54,-30;-87,0;\n-8,-89;13,-66;44,-37;87,-8;\n-9,-56;-9,-35;\n-39,-24;27,-32;20,18;\n-37,-2;24,-6;\n-38,25;16,19;\n-39,-23;-44,92;-17,72;\n36,24;16,47;-1,58;\n-24,39;15,72;44,85;73,95;\n\n前\n-45,-84;-35,-53;\n42,-89;8,-54;\n-72,-32;-6,-41;34,-44;81,-45;\n-55,-12;-55,15;-56,41;-59,81;\n-55,-12;-14,-16;-16,10;-16,39;-14,88;-27,85;\n-53,14;-18,12;\n-56,41;-19,39;\n15,-6;15,37;\n57,-27;60,89;40,80;\n\n後\n-41,-80;-58,-60;-75,-47;\n-39,-37;-59,-8;-89,19;\n-62,-3;-62,14;-66,75;\n26,-88;-12,-52;15,-41;\n40,-57;-19,-5;23,-14;48,-22;\n40,-35;54,-21;64,-4;\n12,-7;-9,28;-23,46;-35,57;\n2,13;44,8;44,8;26,40;8,56;-14,68;\n-5,26;30,51;59,66;86,75;\n\n南\n-57,-46;59,-59;\n-8,-80;-9,-14;\n-71,-1;-65,79;\n-72,0;-39,-7;37,-14;75,-14;73,38;67,75;60,87;50,83;\n-28,5;-20,23;\n25,-3;1,21;\n-32,29;25,23;\n-38,53;31,47;\n-7,29;-5,80;\n\n校\n-89,-24;-64,-28;-27,-39;\n-53,-79;-57,19;-58,81;\n-58,-26;-74,21;-93,46;\n-55,-26;-28,-3;\n26,-83;27,-54;\n-9,-49;43,-55;72,-62;\n6,-32;-2,-11;-9,-3;\n50,-39;68,-22;74,-16;\n48,-17;19,43;-5,63;-24,74;\n0,3;34,41;66,68;84,79;92,81;\n\n時\n-84,-56;-81,38;\n-82,-52;-34,-57;-37,31;\n-81,-10;-37,-14;\n-81,37;-38,32;\n-12,-55;66,-61;\n24,-93;22,-23;\n-23,-15;51,-21;84,-23;\n-20,14;79,8;\n48,-16;46,83;45,91;28,78;\n-11,30;2,50;\n\n高\n-6,-88;-5,-54;\n-58,-46;19,-55;57,-57;\n-28,-23;-23,0;\n-27,-24;26,-30;20,-4;\n-22,-1;20,-4;\n-61,29;-55,85;\n-60,29;-24,23;38,17;66,16;52,88;41,83;\n-22,40;-19,66;\n-21,41;-21,41;25,38;21,63;\n-18,66;20,62;\n\n書\n-43,-70;39,-73;26,-25;\n-75,-37;-7,-46;81,-52;\n-42,-20;25,-26;\n-42,2;29,-5;\n-65,36;-1,28;60,30;\n-11,-97;-10,28;\n-44,53;-36,90;\n-44,50;-5,48;38,48;29,88;\n-39,70;31,67;\n-35,90;27,88;\n\n魚\n-20,-92;-41,-67;-65,-48;\n-30,-79;28,-84;12,-56;-2,-42;\n-56,-34;-51,22;\n-55,-34;40,-41;58,-40;55,-9;46,22;\n-2,-37;-2,21;\n-53,-8;54,-11;\n-51,22;44,20;\n-59,47;-70,72;-79,82;\n-25,58;-17,83;\n22,56;38,85;\n62,53;78,69;84,80;\n\n週\n-7,-78;-3,-61;-6,-17;-11,27;-17,45;\n-5,-77;17,-82;71,-83;70,-49;71,15;73,53;55,48;\n9,-55;56,-60;\n31,-74;31,-39;28,-32;\n3,-28;57,-34;\n13,-11;16,17;\n13,-11;45,-14;41,14;\n17,17;39,15;\n-62,-73;-39,-54;-46,-49;\n-83,-2;-47,-9;-53,5;-52,18;-48,27;-53,40;-69,46;-85,49;\n-85,49;-50,54;-4,69;46,83;90,81;\n\n飲\n-42,-87;-62,-51;-92,-21;\n-43,-87;-9,-61;\n-43,-54;-43,-29;\n-68,-19;-20,-27;-20,-4;-23,10;\n-65,0;-23,-8;\n-65,21;-23,11;-23,11;\n-68,-18;-66,27;-71,83;-36,52;\n-45,34;-23,64;\n19,-81;8,-41;-1,-26;\n8,-41;79,-55;50,-26;\n24,-30;22,14;9,46;-11,73;-19,76;\n22,15;66,65;94,78;\n\n道\n-5,-82;7,-60;\n56,-92;27,-59;\n-22,-46;42,-54;75,-55;\n18,-50;9,-26;\n-4,-21;-6,60;\n-4,-21;20,-25;44,-25;44,56;\n-3,3;42,-1;\n-4,29;41,27;\n-6,60;40,56;\n-74,-71;-63,-61;-51,-54;-56,-50;\n-90,4;-49,-6;-59,14;-58,27;-50,37;-57,51;-72,60;-88,63;\n-89,61;-62,63;-26,74;19,81;67,87;90,84;\n\n買\n-54,-80;-44,-44;\n-55,-83;1,-88;50,-90;67,-89;52,-51;\n-16,-83;-17,-48;\n14,-88;11,-49;\n-44,-44;15,-50;50,-51;\n-34,-26;-32,50;-33,54;\n-34,-28;36,-32;36,52;\n-31,-3;33,-7;\n-31,22;34,20;\n-33,53;34,50;\n-11,57;-29,81;-48,91;\n13,56;47,79;55,86;\n\n間\n-70,-78;-14,-82;-22,-11;\n-66,-45;-21,-50;\n-65,-6;-24,-11;\n-65,-73;-67,80;\n15,-83;17,-15;\n14,-83;72,-86;70,90;58,84;\n18,-50;69,-50;\n16,-14;67,-17;\n-25,19;-23,51;-23,78;\n-24,19;27,13;20,77;\n-20,43;22,41;\n-22,76;18,75;\n\n話\n-57,-80;-31,-68;\n-85,-29;-24,-40;\n-72,3;-38,-5;\n-71,31;-36,22;\n-73,51;-70,85;\n-72,50;-33,41;-32,54;-39,80;\n-68,87;-38,81;\n51,-81;6,-44;\n-13,-5;81,-18;\n30,-62;31,-47;28,27;\n-5,35;2,79;\n-4,36;35,29;71,28;61,76;\n1,79;61,75;\n\n新\n-49,-84;-48,-50;\n-86,-47;-10,-58;\n-68,-44;-65,-8;\n-30,-52;-35,-14;\n-93,3;-16,-16;\n-84,31;-21,14;\n-48,-5;-48,82;\n-51,26;-61,53;-83,76;\n-48,29;-23,49;\n76,-84;16,-50;\n10,-52;14,-36;9,-7;0,31;-6,44;\n12,-16;55,-23;91,-26;\n53,-20;53,76;52,87;\n\n電\n-45,-79;16,-84;31,-84;\n-80,-47;-82,-19;\n-80,-48;-10,-56;54,-56;78,-53;60,-33;\n-13,-81;-12,-8;\n-49,-41;-32,-34;\n-55,-21;-37,-15;\n8,-46;28,-36;\n5,-24;25,-16;\n-53,10;-46,49;\n-54,9;31,1;25,42;\n-49,26;27,23;\n-46,47;23,42;\n-16,7;-17,74;-9,83;11,87;39,86;60,82;64,76;65,69;65,67;\n\n読\n-65,-86;-41,-72;\n-91,-40;-28,-49;\n-80,-12;-45,-16;\n-80,18;-47,11;\n-86,40;-82,53;-79,78;\n-87,40;-44,34;-49,72;\n-79,76;-50,72;\n-8,-58;74,-66;\n28,-91;26,-33;\n3,-29;50,-34;\n-16,-4;-18,18;\n-13,-3;5,-9;80,-14;61,7;\n10,11;7,29;-1,53;-15,74;-20,79;\n31,8;27,65;38,78;56,82;81,80;94,73;91,63;\n\n語\n-65,-81;-35,-70;\n-88,-35;-18,-47;\n-72,-6;-72,-6;-37,-11;\n-70,23;-38,14;\n-73,43;-70,81;\n-74,45;-32,35;-36,72;\n-69,78;-37,70;\n5,-58;67,-65;\n34,-60;20,9;\n-3,-21;65,-29;64,-17;53,7;\n-14,16;51,9;90,10;\n1,34;7,73;\n2,35;33,29;71,30;59,71;\n6,74;58,70;\n\n駅\n-72,-75;-72,20;\n-74,-72;-21,-85;\n-44,-75;-41,14;\n-71,-42;-22,-54;\n-71,-13;-21,-26;\n-73,18;-15,9;-22,63;-31,88;-38,86;\n-92,49;-89,72;\n-63,44;-63,57;\n-50,36;-48,44;\n-38,32;-35,39;\n5,-69;77,-79;62,-33;\n11,-25;62,-33;\n6,-68;11,-11;6,21;1,51;-7,70;\n26,-24;59,26;88,62;100,74;\n\n聞\n-66,-75;-13,-80;-18,-29;\n-65,-49;-19,-54;\n-63,-19;-18,-28;\n-63,-75;-65,-2;-69,77;\n19,-81;18,-27;\n19,-82;75,-82;71,-23;70,84;51,79;\n22,-53;70,-58;\n18,-25;70,-28;\n-39,6;26,-1;\n-20,7;-18,54;\n-16,23;10,19;\n-17,39;11,36;\n-44,62;19,47;\n15,4;16,74;\n\n#"},
    {4, L"#"},
    {3, L"#"},
    {2, L"#"},
    {1, L"#"},
};
