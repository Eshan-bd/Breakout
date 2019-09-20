
class Object
{
public:
	Object();
	virtual ~Object();

	// get inputs and change positions
	virtual void update(Uint32& dt);

	// Render the sprite
/*	void render(Texture& tex);

	inline int getX() const { return x; }

	inline int getY() const { return y; }

	inline int getWidth() const { return mTexture.w; }

	inline int getHeight() const { return mTexture.h; }
	*/
	};
