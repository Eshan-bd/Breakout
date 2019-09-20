#include <vector>
#include <memory>

class Sprite;

class Collision
{
public:
	static std::vector<Sprite> colliders;
	Collision();
	~Collision();

	inline void addCollider(Sprite &sprite) { colliders.push_back(sprite); };

	bool checkCollision(std::shared_ptr<Sprite> col1, std::shared_ptr<Sprite> col2);
};
