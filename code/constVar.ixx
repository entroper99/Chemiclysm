#include <SDL.h>

export module constVar;

import std;

export constexpr int DARK_VISION_HALF_W = 18; //어둠시야
export constexpr int DARK_VISION_HALF_H = 9; //어둠시야

export constexpr int GRAY_VISION_HALF_W = 23; //주변 FOV 회색으로 바꾸는 최대 W
export constexpr int GRAY_VISION_HALF_H = 23; //주변 FOV 회색으로 바꾸는 최대 H

export constexpr int CHUNK_SIZE_X = 13; //청크의 x길이
export constexpr int CHUNK_SIZE_Y = 13; //청크의 y길이
export constexpr int CHUNK_SIZE_Z = 1; //청크의 z길이, 현재 1로 미사용됨
export constexpr int MAX_FONT_SIZE = 32;
export constexpr int EX_INPUT_TEXT_MAX = 30;
export constexpr int EQUIP_ITEM_MAX = 10;
export constexpr int LOOT_ITEM_MAX = 9;
export constexpr int INVENTORY_ITEM_MAX = 9;
export constexpr int DMG_FLAG_SIZE = 3;
export constexpr int TALENT_SIZE = 19;
export constexpr int MAX_VEHICLE_SIZE = 31;
export constexpr int CHUNK_LOADING_RANGE = 5;
export constexpr int MINIMAP_DIAMETER = 41; //미니맵의 지름 (홀수)
export constexpr int SECTOR_SIZE = 400; // 절차적 맵 생성할 때 작용하는 범위
export constexpr int TOLERANCE_LSTICK = 10000; //LStick이 이 값을 넘어야 판정이 일어남
export constexpr int TOLERANCE_HOLD_DEL_XY = 20; //이 값 이상 움직일 경우 홀드 이벤트가 일어나지 않음

export constexpr int MARKER_LIMIT_DIST = 100; //플레이어로부터 100칸 이상 떨어지면 마커가 그려지지 않음

export constexpr std::array<int, 27> expTable =
{ 50, 100, 150, 200, 250, 300, 350, 400, 450,
550, 650, 750, 850, 950, 1050, 1150, 1250, 1350,
1500, 1650, 1800, 1950, 2100, 2250, 2400, 2550, 2750 };

export namespace col
{
    constexpr SDL_Color black = { 0x00, 0x00, 0x00 };
    constexpr SDL_Color yellow = { 0xff,0xff,0x00 };
    constexpr SDL_Color brown = { 0x5c,0x33,0x17 };
    constexpr SDL_Color gray = { 0x63,0x63,0x63 };
    constexpr SDL_Color green = { 0x00,0x6e,0x00 };
    constexpr SDL_Color blueberry = { 0x64,0x64,0xff };
    constexpr SDL_Color red = { 0xf9,0x29,0x29 };
    constexpr SDL_Color white = { 0xff,0xff,0xff };
    constexpr SDL_Color lightGray = { 0x96,0x96,0x96 };
    constexpr SDL_Color blue = { 0x21,0x4a,0xea };
    constexpr SDL_Color yellowGreen = { 0x3a, 0xf5, 0x43 };
    constexpr SDL_Color monaLisa = { 0xff,0x96,0x96 };
    constexpr SDL_Color bondiBlue = { 0x00,0x96,0xb4 };
    constexpr SDL_Color hotPink = { 0x8b,0x3a,0x62 };
    constexpr SDL_Color pink = { 0xfe,0x00,0xfe };
    constexpr SDL_Color skyBlue = { 0x00,0xf0,0xff };
    constexpr SDL_Color blueDart = { 0x4e,0x8e,0xd2 };
    constexpr SDL_Color orange = { 0xf2, 0x65, 0x22 };
    constexpr SDL_Color cyan = { 0x00,0xa3,0xd2 };
};

export namespace lowCol
{
    constexpr SDL_Color black = { 0x00,0x00,0x00 };
    constexpr SDL_Color white = { 0xff,0xff,0xff };
    constexpr SDL_Color red = { 0xd0,0x3f,0x3f };
    constexpr SDL_Color orange = { 0xd0,0x7a,0x3f };
    constexpr SDL_Color yellow = { 0xd0,0xc3,0x3f };
    constexpr SDL_Color green = { 0x75,0xd0,0x3f };
    constexpr SDL_Color mint = { 0x3f,0xd0,0x7f };
    constexpr SDL_Color skyBlue = { 0x3f,0xba,0xd0 };
    constexpr SDL_Color deepBlue = { 0x20,0x50,0xa8 };
    constexpr SDL_Color blue = { 0x2b,0x81,0xe8 };
    constexpr SDL_Color purple = { 0x43,0x3e,0x8e };
    constexpr SDL_Color pink = { 0xbe,0x3f,0xd0 };
    constexpr SDL_Color crimson = { 0xd0,0x3f,0x89 };
};

export enum class act
{
    null,       //일반 게임플레이
    blank,      //빈칸
    status,     //상태창
    ability,    //특수능력
    inventory,  //인벤토리
    bionic,     //바이오닉
    talent,      //재능
    runMode,    //달리기 모드
    menu,       //메뉴

    identify,   //감정
    vehicle,    //차량
    alchemy,    //연금술
    god, //신앙
    map, //지도

    closeDoor, //문닫기


    armor,  //레이드아머
    cooking,    //요리
    loot,       //줍기
    pick,       //넣기(가방에)
    wield,      //들기
    equip,      //장비
    pickSelect, //줍기(선택)
    selectAll,  //선택(전부) 필요없음
    searching,  //검색
    sorting,    //정렬
    select,     //선택
    eat,        //먹기
    apply,      //사용
    selectMode, //선택 모드
    droping,    //버리기
    throwing,   //던지기
    dirSelect,  //방향선택
    coordSelect,//위치선택
    mutation,   //돌연변이
    craft,      //조합
    construct,  //건축
    open,       //가방열기
    test,       //테스트 기능
    insert,     //아이템 넣기(가방에 옮기기)
    reload,     //아이템 장전
    reloadBulletToMagazine, //탄환 장전
    unloadBulletFromMagazine, //탄환 분리
    reloadMagazine, //탄창 장전, 총과 탄창 양쪽에 있으며 기능이 다름
    unloadMagazine, //탄창 분리
    reloadBulletToGun, //탄환 장전
    unloadBulletFromGun, //탄환 분리

    turnLeft,//좌회전
    wait,//1턴대기
    turnRight,//우회전
    startEngine,//엔신시동
    stopEngine,//엔진끄기
    shiftGear,//기어변경
    accel,//액셀
    brake,//브레이크
    autoGear,//자동변속기

    collectiveLever,
    cyclicLever,
    rpmLever,
    tailRotorPedalL,
    tailRotorPedalR,

    confirm,//확인
    rotate,//회전
    cancel,//취소

    quickSlot,
    skillActive,
    skillToggle,

    inspect,
    unbox,
    pull,

    climb,
    swim,
    ride,

    //skillInfo,
};

export namespace humanCustom
{
    enum class skin
    {
        null,
        white,
        yellow,
        brown,
        black
    };

    enum class eyes
    {
        null,
        close,
        red,
        blue,
        black,
    };


    enum class scar
    {
        null,
        darkCircles
    };

    enum class beard
    {
        null,
        mustache
    };

    enum class hair
    {
        null,
        commaBlack,
        bob1Black,
        ponytail,
        middlePart,
    };


};

export namespace axis
{
    constexpr int x = 0;
    constexpr int y = 1;
    constexpr int z = 2;
};


export namespace mapFlag
{
    constexpr int floor = 0; //바닥의 종류
    constexpr int wall = 1; //벽의 종류
    constexpr int base = 2; //
    constexpr int opaque = 3; //시야를 막는 방해물 여부
    constexpr int fov = 4; //현재 fov 상태
    constexpr int walkable = 5; //보행 가능 여부

    // ※ 광원
    //아래 RGB값의 보색만큼 안개의 색이 빠짐 {R,G,B} = {255,0,0}일 경우
    //{255,255,255}-{0,255,255}해서 {255,0,0}, 최댓값은 항상 255이다.
    constexpr int light = 6;
    constexpr int redLight = 7;
    constexpr int greenLight = 8;
    constexpr int blueLight = 9;
};

export enum entityIndex
{
    test = 1,
    player = 2,
    zombie = 3
};

export enum itemIndex
{
    glitchItem = 0,
    orb = 1,
};



export enum class fovFlag
{
    white,
    black,
    gray
};

export enum class weatherFlag
{
    sunny,
    cloudy,
    rain,
    storm,
    snow,
};


export namespace entityFlag
{
    constexpr int name = 0;
    constexpr int index = 1;
    constexpr int nameIndex = 2;
    constexpr int sprIndex = 3;
    constexpr int category = 4;
    constexpr int temperature = 5;
    constexpr int weight = 6;
    constexpr int volume = 7;
    constexpr int HD = 8;
    constexpr int SH = 9;
    constexpr int EV = 10;
    constexpr int rFire = 11;
    constexpr int rCold = 12;
    constexpr int rElec = 13;
    constexpr int rCorr = 14;
    constexpr int rRad = 15;
    constexpr int maxHP = 16;

    constexpr std::array<int, 10> indexPart = { 17, 23, 29, 35, 41, 47, 53, 59, 65, 71 };
    constexpr std::array<int, 10> rPiercePart = { 18, 24, 30, 36, 42, 48, 54, 60, 66, 72 };
    constexpr std::array<int, 10> rCutPart = { 19, 25, 31, 37, 43, 49, 55, 61, 67, 73 };
    constexpr std::array<int, 10> rBashPart = { 20, 26, 32, 38, 44, 50, 56, 62, 68, 74 };
    constexpr std::array<int, 10> encMaxPart = { 21, 27, 33, 39, 45, 51, 57, 63, 69, 75 };
    constexpr std::array<int, 10> accPart = { 22, 28, 34, 40, 46, 52, 58, 64, 70, 76 };

    constexpr int strength = 77;
    constexpr int intelligence = 78;
    constexpr int dexterity = 79;
    constexpr int corpseItemIndex = 80;
    constexpr int downImageIndex = 81;
    constexpr int corpseImageIndex = 82;
    constexpr int portraitImageIndex = 83;
    constexpr int atk = 84;
    constexpr int atkType = 85;
    constexpr int atkSpd = 86;
    constexpr int movSpd = 87;
    constexpr int flySpd = 88;
    constexpr int swimSpd = 89;
    constexpr int unique = 90;
    constexpr int regen = 91;
    constexpr int blood = 92;
    constexpr int sight = 93;
    constexpr int smell = 94;
};

export namespace dmgFlag
{
    constexpr int partIndex = 0;
    constexpr int dmg = 1;
    constexpr int type = 2;
};


/*
* 파츠는 0번이 메인이고 0번이 0이 되면 사망함
* 데미지를 가하면 1번 이상의 파츠인덱스에 누적되는데 이때 0번에도 같은 데미지가 들어감, 기타 출혈같은 요소로도 HP가 사라짐
*/
export namespace partType
{
    constexpr unsigned __int8 null = 0;
    constexpr unsigned __int8 head = 1;
    constexpr unsigned __int8 torso = 2;
    constexpr unsigned __int8 larm = 3;
    constexpr unsigned __int8 rarm = 4;
    constexpr unsigned __int8 lleg = 5;
    constexpr unsigned __int8 rleg = 6;
    constexpr unsigned __int8 tail = 7;

    constexpr unsigned __int8 turret = 8;
    constexpr unsigned __int8 camera = 9;
    constexpr unsigned __int8 body = 10;
    constexpr unsigned __int8 lCaterpillar = 11;
    constexpr unsigned __int8 rCaterpillar = 12;
};

export namespace wound
{
    constexpr int pierce = 0; //관통상
    constexpr int cut = 1; //절단상
    constexpr int bash = 2; //타박상
    constexpr int fracture = 3; //골절 : 피격시 타박상 포인트가 높을 경우 발생, 부목으로만 치료 가능 20% 고정 손실
    constexpr int burn = 4; //화상 : 치료 불가능, 의사에게 가야함
    constexpr int frostbite = 5; //동상 : 따뜻한 곳에 가면 아주 조금씩 재생됨
    constexpr int shock = 6; //쇼크 : 정신적인 충격, 머리에만 발생함
};

export namespace talentFlag
{
    constexpr int fighting = 0;
    constexpr int dodging = 1;
    constexpr int stealth = 2;
    constexpr int throwing = 3;
    constexpr int unarmedCombat = 4;
    constexpr int piercingWeapon = 5;
    constexpr int cuttingWeapon = 6;
    constexpr int bashingWeapon = 7;
    constexpr int archery = 8;
    constexpr int gun = 9;
    constexpr int electronics = 10;
    constexpr int chemistry = 11;
    constexpr int mechanics = 12;
    constexpr int computer = 13;
    constexpr int medicine = 14;
    constexpr int cooking = 15;
    constexpr int fabrication = 16;
    constexpr int social = 17;
    constexpr int architecture = 18;
};

export enum class msgFlag
{
    deact,
    normal,
    input,
};

export enum class itemFlag
{
    TWOHANDED,
    CANEQUIP,
    NONSTACK,
    GUN,
    MAGAZINE,
    AMMO,
    BOOKMARK1,
    BOOKMARK2,
    BOOKMARK3,
    BOOKMARK4,
    BOOKMARK5,
    BOOKMARK6,
    POWERED,//동력공구
    VFRAME,//차량프레임 : 설치 가능
    RAIDARMOR,//아머프레임 : 설치 가능
    WHITEFILTER,
    GRAYFILTER,//검색 및 조합 GUI에서 아이템을 회색으로 표시하게 만듬
    BLACKFILTER,//조합 GUI에서 미해당 아이템을 검은색으로 표시하게 만듬(미표시)
    COORDCRAFT,//좌표조합, 건축물이나 차량 등
    ALCHEMYTOOL,//연금술에서 사용 가능한 도구
    ALCHEMYMATERIAL, //연금술에 사용 가능한 재료
    LIQUID, //액체 상
    GAS, // 기체 상
    VPART, //차량부품
    TRANSPARENT_WALL, //투명벽

    VPART_WALL_CONNECT,//차벽같이 주변에 연결되는 16타일
    VPART_DIR_DEPEND,//방향에 의존하여 16방향이 존재하는 프롭
    VPART_DOOR_OPEN,
    VPART_DOOR_CLOSE,

    VEH_ROOF,

    LIGHT_ON,
    LIGHT_OFF,

    TIRE_NORMAL,
    TIRE_STEER,

    PROP, //설치 가능한 아이템
    PROP_BIG,//48px가 아니라 80px*80px의 giantVehicleset 참조함
    PROP_WALKABLE,//이동가능 프롭
    PROP_BLOCKER,//시야방해 프롭
    PROP_DEPTH_LOWER,//기존 설치물(&엔티티)들과 겹쳐지지 않고 바닥에 깔리는 설치물


    PIPE_CNCT_RIGHT,
    PIPE_CNCT_TOP,
    PIPE_CNCT_LEFT,
    PIPE_CNCT_BOT,

    WIRE_CNCT_RIGHT,
    WIRE_CNCT_TOP,
    WIRE_CNCT_LEFT,
    WIRE_CNCT_BOT,

    CONVEYOR_CNCT_RIGHT,
    CONVEYOR_CNCT_TOP,
    CONVEYOR_CNCT_LEFT,
    CONVEYOR_CNCT_BOT,

    WIRE,
    PIPE,
    CONVEYOR,

    RAIL,

    RAIL_CNCT_TOP,
    RAIL_CNCT_BOT,
    RAIL_CNCT_LEFT,
    RAIL_CNCT_RIGHT,

    //선로전환기에서 고정된 레일
    RAIL_INPUT_TOP,
    RAIL_INPUT_BOT,
    RAIL_INPUT_LEFT,
    RAIL_INPUT_RIGHT,

    RAIL_BUFFER,

    NOT_RECIPE, //조합법에 따로 추가되지 않음(회전된 설치물같은 중복 설치물들)

    /// 여기서부터 새로 추가해야됨
    TREE, //나무
    PLANT, //식물
    PLANT_SEASON_DEPENDENT, //계절의존식물
    PLANT_GROWTH_DEPENDENT, //성장의존식물
    MUSHROOM, //버섯
    FLOOR, //바닥타일
    WALL, //벽
    CEIL, //천장
    WATER_SHALLOW, //얕은물
    WATER_DEEP, //깊은물
    FRESHWATER, //담수
    SEAWATER, //해수
    TILE_SEASON, //계절에 따라 변하는 타일
    DOOR,
    UPSTAIR,
    DOWNSTAIR,
    SIGN,//나무표지판같이 문구를 저장하는 객체


    DOOR_CLOSE,
    DOOR_OPEN,

    TRAIN_WHEEL, //열차바퀴

    PROP_GAS_OBSTACLE_ON,
    PROP_GAS_OBSTACLE_OFF,
    WALL_GAS_PERMEABLE,

    POCKET,
    CAN_CLIMB,
};

export namespace toolQuality
{
    constexpr int none = 0;
    constexpr int screwDriving = 1;
    constexpr int drilling = 2;
    constexpr int welding = 3;
    constexpr int soldering = 4;
    constexpr int cutting = 5;
    constexpr int sawing = 6;
    constexpr int hammering = 7;
    constexpr int digging = 8;
    constexpr int sewing = 9;
    constexpr int distillation = 10;
    constexpr int boiling = 11;
    constexpr int frying = 12;
    constexpr int roasting = 13;
    constexpr int boltTurning = 14;
    constexpr int woodCutting = 15;
    constexpr int metalCutting = 16;
    constexpr int metalDrilling = 17;
    constexpr int refrigeration = 18;
    constexpr int heating = 19;
};

export enum class itemAct
{
    pick = 0,
    wield = 1,
    drop = 2,
    pitch = 3,

    wear = 4,
    takeOff = 5,
    repair = 6,
    disasm = 7,

    apply = 8,
    eat = 9,
    read = 10,
    reload = 11,
    unload = 12,
    open = 13,
};


export enum class playerSpriteCategory
{
    oneHanded = 0,
    twoHanded = 2,
    sitOneHanded = 4,
    sitTwoHanded = 6,
    runOneHanded = 8,
    runTwoHanded = 10,
};

export enum class btn
{
    keypad6 = 0,
    keypad9 = 1,
    keypad8 = 2,
    keypad7 = 3,
    keypad4 = 4,
    keypad1 = 5,
    keypad2 = 6,
    keypad3 = 7,
    keypad5 = 8,
    a = 9,
    b = 10,
    x = 11,
    y = 12,
    l1 = 13,
    r1 = 14,
    l2 = 15,
    r2 = 16,
};



export enum class storageType
{
    null,//임시용
    equip,//장비
    stack,//스택
    pocket,//아이템의 내부 주머니
    temp,//임시용
    recipe,//레시피(플레이어용)
};

export enum class aniFlag
{
    null,
    move,
    atk,
    drop,
    winUnfoldOpen,
    winUnfoldClose,
    winSlipOpen,
    winSlipClose,
    throwing,
    popUpLetterbox, //GUI에 존재하는 HUD 전용 애니메이션
    popDownLetterbox,
    popUpSingleLetterbox,
    shotSingle,
    shotBurst,
    shotAuto,
    shotArrow,
    propRush,
    trainRush,
    quickSlotPopLeft,
    quickSlotPopRight,
    fireStorm,
};

export enum class input
{
    mouse,
    touch,
    keyboard,
    gamepad
};

export enum class msgOption
{
    okay,
    cancel,
    yes,
    no,
    confirm,
    left,
    right
};

export enum class tabFlag
{
    autoAtk,
    closeWin,
    back,
    confirm,
    aim,
};

export enum class sortFlag
{
    null,
    weightDescend,
    weightAscend,
    volumeDescend,
    volumeAscend,
    equip,
};

export namespace equip
{
    constexpr int none = 0;
    constexpr int normal = 1;
    constexpr int left = 2;
    constexpr int right = 3;
    constexpr int both = 4;
};

export enum class turn
{
    playerInput,
    playerAnime,
    VehicleAI,
    VehicleAnime,
    monsterAI,
    monsterAnime,
};

export namespace keyIcon
{
    constexpr int blankRect = 0;

    constexpr int keyboard_1 = 1;
    constexpr int keyboard_2 = 2;
    constexpr int keyboard_3 = 3;
    constexpr int keyboard_4 = 4;
    constexpr int keyboard_5 = 5;
    constexpr int keyboard_6 = 6;
    constexpr int keyboard_7 = 7;
    constexpr int keyboard_8 = 8;
    constexpr int keyboard_9 = 9;
    constexpr int keyboard_0 = 10;

    constexpr int keyboard_Num1 = 11;
    constexpr int keyboard_Num2 = 12;
    constexpr int keyboard_Num3 = 13;
    constexpr int keyboard_Num4 = 14;
    constexpr int keyboard_Num5 = 15;
    constexpr int keyboard_Num6 = 16;
    constexpr int keyboard_Num7 = 17;
    constexpr int keyboard_Num8 = 18;
    constexpr int keyboard_Num9 = 19;
    constexpr int keyboard_Num0 = 20;

    constexpr int keyboard_F1 = 21;
    constexpr int keyboard_F2 = 22;
    constexpr int keyboard_F3 = 23;
    constexpr int keyboard_F4 = 24;
    constexpr int keyboard_F5 = 25;
    constexpr int keyboard_F6 = 26;
    constexpr int keyboard_F7 = 27;
    constexpr int keyboard_F8 = 28;
    constexpr int keyboard_F9 = 29;
    constexpr int keyboard_F10 = 30;
    constexpr int keyboard_F11 = 31;
    constexpr int keyboard_F12 = 32;

    constexpr int keyboard_H = 33;
    constexpr int keyboard_J = 34;
    constexpr int keyboard_K = 35;
    constexpr int keyboard_L = 36;
    constexpr int keyboard_Y = 37;
    constexpr int keyboard_U = 38;
    constexpr int keyboard_B = 39;
    constexpr int keyboard_N = 40;
    constexpr int keyboard_A = 41;
    constexpr int keyboard_S = 42;
    constexpr int keyboard_Z = 43;
    constexpr int keyboard_X = 44;

    constexpr int keyboard_Tab = 45;
    constexpr int keyboard_Enter = 46;
    constexpr int keyboard_PgUp = 47;
    constexpr int keyboard_PgDn = 48;

    constexpr int pad_X = 49;
    constexpr int pad_Y = 50;
    constexpr int pad_A = 51;
    constexpr int pad_B = 52;
    constexpr int pad_L = 53;
    constexpr int pad_R = 54;
    constexpr int pad_LStick = 55;
    constexpr int pad_ZL = 56;
    constexpr int pad_ZR = 57;

    constexpr int pad_Right = 58;
    constexpr int pad_Up = 59;
    constexpr int pad_Left = 60;
    constexpr int pad_Down = 61;

    constexpr int keyboard_C = 62;
    constexpr int keyboard_V = 63;

    constexpr int keyboard_LShift = 64;
    constexpr int keyboard_RShift = 65;

    constexpr int duelSense_L1 = 66;
    constexpr int duelSense_L2 = 67;
    constexpr int duelSense_R1 = 68;
    constexpr int duelSense_R2 = 69;

    constexpr int duelSense_X = 70;
    constexpr int duelSense_CIR = 71;
    constexpr int duelSense_RECT = 72;
    constexpr int duelSense_TRI = 73;
    constexpr int duelSense_LStick = 74;
    constexpr int duelSense_RStick = 75;
  
    constexpr int duelSense_RIGHT = 77;
    constexpr int duelSense_TOP = 78;
    constexpr int duelSense_LEFT = 79;
    constexpr int duelSense_BOT = 80;
    constexpr int duelSense_OPTIONS = 81;
    constexpr int duelSense_SHARE = 82;

    ////////

    constexpr int joyCon_L = 88;
    constexpr int joyCon_ZL = 89;
    constexpr int joyCon_R = 90;
    constexpr int joyCon_ZR = 91;

    constexpr int joyCon_A = 92;
    constexpr int joyCon_B = 93;
    constexpr int joyCon_X = 94;
    constexpr int joyCon_Y = 95;
    constexpr int joyCon_LStick = 96;
    constexpr int joyCon_RStick = 97;

    constexpr int joyCon_RIGHT = 99;
    constexpr int joyCon_TOP = 100;
    constexpr int joyCon_LEFT = 101;
    constexpr int joyCon_BOT = 102;
    constexpr int joyCon_PLUS = 103;
    constexpr int joycon_MINUS = 104;
};

export namespace sprInf
{
    constexpr int walk = 0;
    constexpr int run = 6;
    constexpr int sit = 12;
    constexpr int crawl = 18;
};

export enum class itemCategory
{
    weapon,
    equipment,
    tool,
    consumable,
    bionic,
    vehicle,
    structure,
    material,
};

export enum class itemSubcategory
{
    weapon_piercing,
    weapon_cutting,
    weapon_bashing,
    weapon_shooting,
    weapon_throwing,

    equipment_clothing,
    equipment_hat,
    equipment_gloves,
    equipment_shoes,
    equipment_accessory,

    tool_hand,
    tool_power,
    tool_container,
    tool_device,
    tool_document,
    tool_etc,

    consumable_food,
    consumable_medicine,
    consumable_ammo,
    consumable_fuel,
    consumable_etc,

    vehicle_frame,//프레임
    vehicle_engine,//엔진 : 가솔린, 디젤, 전기모터
    vehicle_exterior,//외장 : 바퀴, 차문, 트렁크문
    vehicle_transport,//수송 : 트렁크, 의자
    vehicle_energy,//에너지 : 배터리, 발전기
    vehicle_device,//장치 : 오디오, 조종장치 등

    bionic_core,//코어
    bionic_active,//발동계
    bionic_passive,//지속계
    bionic_toggle,//전환계
    bionic_generator,//생산계
    bionic_storage,//저장계

    structure_wall,
    structure_floor,
    structure_ceil,
    structure_prop,
    structure_electric,
    structure_pneumatic,

    material_chemical,
    material_biological,
    material_mechanical,
    material_electrical,
    material_etc,
};

export enum class godFlag
{
    none,
    teshub,
    buddha,
    jesus,
    amaterasu,
    yudi,
    ra,
};

export namespace entityCategory
{
    constexpr int none = 0;
    constexpr int human = 1;
    constexpr int zombie = 2;
    constexpr int robot = 3;
};

export namespace bodyTemplateFlag
{
    constexpr int none = 0;
    //모든 부위가 파괴되면 사망
    constexpr int human = 1;
    //머리 몸통 왼팔 오른팔 왼다리 오른다리
    //머리나 몸통 터지면 즉사, 팔 터지면 공격력 30% 감소, 다리 터지면 이속 30% 감소
    constexpr int zombie = 2;
    //머리 몸통 왼팔 오른팔 왼다리 오른다리
    //몸통 터지면 즉사, 팔 터지면 공격력 30% 감소, 다리 터지면 이속 30% 감소, 머리 터지면 시야 0
    constexpr int tank = 3;
    //포탑 차체 좌무한궤도 우무한궤도
    //차체 터지면 즉사, 포탑 터지면 사격불가, 궤도 터지면 각각 이동속도 30% 감소
};

export namespace partsFlag
{
    constexpr int index = 0;
    constexpr int hp = 1;
    constexpr int acc = 2;
    constexpr int maxHP = 3;
};

export namespace bulletFlag
{
    constexpr int normal = 0;
    constexpr int tracer = 1;
    constexpr int ap = 2;
};

export namespace weaponMode
{
    constexpr int none = 0;
    constexpr int safeMode = 1;
    constexpr int semiAutoMode = 2;
    constexpr int burstMode = 3;
    constexpr int autoMode = 4;
};

//입은 데미지의 종류
export namespace dmgType
{
    constexpr int none = 0; //무속성 공격
    constexpr int pierce = 1;//관통(물리)
    constexpr int cut = 2;//절단(물리)
    constexpr int bash = 3;//타격(물리)
};

//플레이어가 취할 수 있는 공격의 타입, Aim의 5가지 종류(관통, 절단, 타격, 사격, 투척)
export enum class atkType
{
    pierce,
    cut,
    bash,
    shot,
    throwing,
};

export namespace UNI
{
    constexpr int NUL = 0;   // Null char
    constexpr int SOH = 1;   // Start of Heading
    constexpr int STX = 2;   // Start of Text
    constexpr int ETX = 3;   // End of Text
    constexpr int EOT = 4;   // End of Transmission
    constexpr int ENQ = 5;   // Enquiry
    constexpr int ACK = 6;   // Acknowledgment
    constexpr int BEL = 7;   // Bell
    constexpr int BACKSPACE = 8;    // Back Space
    constexpr int TAB = 9;   // Horizontal Tab
    constexpr int LF = 10;   // Line Feed
    constexpr int VT = 11;   // Vertical Tab
    constexpr int FF = 12;   // Form Feed
    constexpr int CR = 13;   // Carriage Return
    constexpr int SO = 14;   // Shift Out / X-On
    constexpr int SI = 15;   // Shift In / X-Off
    constexpr int DLE = 16;  // Data Line Escape
    constexpr int DC1 = 17;  // Device Control 1 (oft. XON)
    constexpr int DC2 = 18;  // Device Control 2
    constexpr int DC3 = 19;  // Device Control 3 (oft. XOFF)
    constexpr int DC4 = 20;  // Device Control 4
    constexpr int NAK = 21;  // Negative Acknowledgement
    constexpr int SYN = 22;  // Synchronous Idle
    constexpr int ETB = 23;  // End of Transmit Block
    constexpr int CAN = 24;  // Cancel
    constexpr int EM = 25;   // End of Medium
    constexpr int SUB = 26;  // Substitute
    constexpr int ESC = 27;  // Escape
    constexpr int FS = 28;   // File Separator
    constexpr int GS = 29;   // Group Separator
    constexpr int RS = 30;   // Record Separator
    constexpr int US = 31;   // Unit Separator
    constexpr int SPACE = 32;
    constexpr int EXCLAMATION_MARK = 33;  // '!'
    constexpr int DOUBLE_QUOTES = 34;  // '"'
    constexpr int HASH = 35;  // '#'
    constexpr int DOLLAR_SIGN = 36;  // '$'
    constexpr int PERCENT_SIGN = 37;  // '%'
    constexpr int AMPERSAND = 38;  // '&'
    constexpr int APOSTROPHE = 39;  // '''
    constexpr int LEFT_PARENTHESIS = 40;  // '('
    constexpr int RIGHT_PARENTHESIS = 41;  // ')'
    constexpr int ASTERISK = 42;  // '*'
    constexpr int PLUS_SIGN = 43;  // '+'
    constexpr int COMMA = 44;  // ','
    constexpr int MINUS_SIGN = 45;  // '-'
    constexpr int PERIOD = 46;  // '.'
    constexpr int SLASH = 47;  // '/'
    constexpr int ZERO = 48;
    constexpr int ONE = 49;
    constexpr int TWO = 50;
    constexpr int THREE = 51;
    constexpr int FOUR = 52;
    constexpr int FIVE = 53;
    constexpr int SIX = 54;
    constexpr int SEVEN = 55;
    constexpr int EIGHT = 56;
    constexpr int NINE = 57;
    constexpr int COLON = 58;  // ':'
    constexpr int SEMICOLON = 59;  // ';'
    constexpr int LESS_THAN_SIGN = 60;  // '<'
    constexpr int EQUAL_SIGN = 61;  // '='
    constexpr int GREATER_THAN_SIGN = 62;  // '>'
    constexpr int QUESTION_MARK = 63;  // '?'
    constexpr int AT_SIGN = 64;  // '@'
    constexpr int A = 65;
    constexpr int B = 66;
    constexpr int C = 67;
    constexpr int D = 68;
    constexpr int E = 69;
    constexpr int F = 70;
    constexpr int G = 71;
    constexpr int H = 72;
    constexpr int I = 73;
    constexpr int J = 74;
    constexpr int K = 75;
    constexpr int L = 76;
    constexpr int M = 77;
    constexpr int N = 78;
    constexpr int O = 79;
    constexpr int P = 80;
    constexpr int Q = 81;
    constexpr int R = 82;
    constexpr int S = 83;
    constexpr int T = 84;
    constexpr int U = 85;
    constexpr int V = 86;
    constexpr int W = 87;
    constexpr int X = 88;
    constexpr int Y = 89;
    constexpr int Z = 90;
    constexpr int LEFT_SQUARE_BRACKET = 91;  // '['
    constexpr int BACKSLASH = 92;  // '\'
    constexpr int RIGHT_SQUARE_BRACKET = 93;  // ']'
    constexpr int CARET = 94;  // '^'
    constexpr int UNDERSCORE = 95;  // '_'
    constexpr int GRAVE_ACCENT = 96;  // '`'
    constexpr int a = 97;
    constexpr int b = 98;
    constexpr int c = 99;
    constexpr int d = 100;
    constexpr int e = 101;
    constexpr int f = 102;
    constexpr int g = 103;
    constexpr int h = 104;
    constexpr int i = 105;
    constexpr int j = 106;
    constexpr int k = 107;
    constexpr int l = 108;
    constexpr int m = 109;
    constexpr int n = 110;
    constexpr int o = 111;
    constexpr int p = 112;
    constexpr int q = 113;
    constexpr int r = 114;
    constexpr int s = 115;
    constexpr int t = 116;
    constexpr int u = 117;
    constexpr int v = 118;
    constexpr int w = 119;
    constexpr int x = 120;
    constexpr int y = 121;
    constexpr int z = 122;
    constexpr int LEFT_CURLY_BRACKET = 123;  // '{'
    constexpr int VERTICAL_BAR = 124;  // '|'
    constexpr int RIGHT_CURLY_BRACKET = 125;  // '}'
    constexpr int TILDE = 126;  // '~'
    constexpr int DEL = 127;   // Delete
};


export enum class gearFlag
{
    park,
    reverse,
    neutral,
    drive,
};

export enum class chunkFlag
{
    none,
    freshwater,//담수
    seawater,//해수
    meadow,//초원
    underground,//지하
    //도로
    //도시
};

export namespace chunkCol
{
    SDL_Color seawater = { 22, 33, 255 };
};

export namespace tileFloorFlag
{
    int none = 0;
    int seawater = 220;
    int grass = 221;
};


export enum class seasonFlag
{
    spring,
    summer,
    autumn,
    winter,
};

export enum class vehFlag
{
    none,
    car,
    heli,
    train,
};


export namespace itemVIPCode
{
    int railRL = 320;
    int railTB = 321;
    int railBR = 322;
    int railTR = 323;
    int railTL = 324;
    int railBL = 325;

    int railSwitchEN = 326;
    int railSwitchES = 327;
    int railSwitchNW = 328;
    int railSwitchNE = 329;
    int railSwitchWN = 330;
    int railSwitchWS = 331;
    int railSwitchSW = 332;
    int railSwitchSE = 333;
};

export enum class skillSrc
{
    NONE,
    BIONIC,
    MUTATION,
    MARTIAL_ART,
    DIVINE_POWER,
    MAGIC,
};

export enum class skillType
{
    ACTIVE,
    PASSIVE,
    TOGGLE,
};

export enum class quickSlotFlag
{
    NONE,
    SKILL,
    ITEM,
};

export enum class CoordSelectFlag
{
    NONE,
    SINGLE_TARGET_SKILL,
    FIRESTORM,
};

export enum class flameFlag
{
    NONE,
    SMALL,
    NORMAL,
    BIG,
};

export enum class gasFlag
{
    NONE,
    SMALL,
    NORMAL,
    BIG,
};