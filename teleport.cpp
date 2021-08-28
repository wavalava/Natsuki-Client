void ClickGui::init() { initialised = true; }

void ClickGui::onMouseClickUpdate(int key, bool isDown) {
	static auto clickGuiMod = moduleMgr->getModule<ClickGuiMod>();
	if (clickGuiMod->isEnabled() && g_Data.isInGame())
	switch (key) {
	case 1:  
		isLeftClickDown = isDown;
  5  Natsuki/Module/Modules/teleport.cpp 
@@ -35,8 +35,9 @@ void Teleport::onTick(C_GameMode* gm) {
	}
	if (!GameData::isRightClickDown()) 
		hasClicked = false;

	if (shouldTP && gm->player->isSneaking()) {

	C_GameSettingsInput* input = g_Data.getClientInstance()->getGameSettingsInput();
		if (shouldTP && GameData::isKeyDown(*input->sneakKey)) {
		tpPos.y += (gm->player->getPos()->y - gm->player->getAABB()->lower.y) + 1;  // eye height + 1
		if (bypass) {
			/*int dist = (int)gm->player->getPos()->dist(tpPos);
  4  Memory/Hooks.cpp 
@@ -1140,12 +1140,12 @@ void Hooks::LoopbackPacketSender_sendToServer(C_LoopbackPacketSender* a, C_Packe

	moduleMgr->onSendPacket(packet);

	if (strcmp(packet->getName()->getText(), "EmotePacket") == 0) {
	/*if (strcmp(packet->getName()->getText(), "EmotePacket") == 0) {
		auto varInt = reinterpret_cast<__int64*>(reinterpret_cast<__int64>(packet) + 0x28);
		auto text = reinterpret_cast<TextHolder*>(reinterpret_cast<__int64>(packet) + 0x30);
		auto bet = reinterpret_cast<unsigned char*>(reinterpret_cast<__int64>(packet) + 0x50);
		logF("emote %llX %s %i", *varInt, text->getText(), *bet);
	}
	} fix emote crashing*/ 

	oFunc(a, packet);
}
  30  SDK/CItem.h 
@@ -232,23 +232,23 @@ class C_Item {
public:
	bool isTool(void) {
		if (getAttackDamage() > 0) return true;           // Does Attack Damage
		if (itemId == 261 || itemId == 262) return true;  // Bow
		if (itemId == 259) return true;                   // Flint n Steel
		if (itemId == 300 || itemId == 301) return true;  // Bow
		if (itemId == 299) return true;                   // Flint n Steel
		return false;
	}
	bool isWeapon(void) {
		if (itemId == 268) return true;			//Wooden Sword
		if (itemId == 272) return true;			//Stone Sword
		if (itemId == 283) return true;			//Gold Sword
		if (itemId == 267) return true;			//Iron Sword
		if (itemId == 276) return true;			//Diamond Sword
		if (itemId == 743) return true;			//Netherite Sword
		if (itemId == 271) return true;			//Wooden Axe
		if (itemId == 275) return true;			//Stone Axe
		if (itemId == 286) return true;			//Gold Axe
		if (itemId == 258) return true;			//Iron Axe
		if (itemId == 279) return true;			//Diamond Axe
		if (itemId == 746) return true;			//Netherite Axe
		if (itemId == 308) return true;         //Wooden Sword
		if (itemId == 312) return true;         //Stone Sword
		if (itemId == 322) return true;         //Gold Sword
		if (itemId == 307) return true;         //Iron Sword
		if (itemId == 316) return true;         //Diamond Sword
		if (itemId == 602) return true;         //Netherite Sword
		if (itemId == 311) return true;         //Wooden Axe
		if (itemId == 315) return true;         //Stone Axe
		if (itemId == 325) return true;         //Gold Axe
		if (itemId == 298) return true;         //Iron Axe
		if (itemId == 319) return true;         //Diamond Axe
		if (itemId == 605) return true;         //Netherite Axe
		return false;
	}
	bool isBlock(void) {
@@ -382,4 +382,4 @@ class ItemRegistry {
public:
	static C_Item*** getItemFromId(void* ptr, int itemId);
	static C_Item*** lookUpByName(void*, void*, TextHolder&);
}; 
};
  2  Utils/Target.cpp 
@@ -29,7 +29,7 @@ bool Target::isValidTarget(C_Entity* ent) {

	auto entityTypeId = ent->getEntityTypeId();

	if (antibot->isEntityIdCheckEnabled() && entityTypeId <= 122 && entityTypeId != 63)
	if (antibot->isEntityIdCheckEnabled() && entityTypeId <= 130 && entityTypeId != 63)
		return false;

	if (entityTypeId == 63) {
