
#ifndef VELOCITY_H
#define VELOCITY_H

	class Velocity
	{
	private:
		float dx;
		float dy;
	public:
		Velocity()
		{
			setDx(0.0);
			setDy(0.0);
		}

		Velocity(float dx, float dy)
		{
			setDx(dx);
			setDy(dy);
		}

		float getDx()
		{
			return dx;
		}

		float getDy()
		{
			return dy;
		}

		void setDx(float dx)
		{
			this->dx = dx;
		}

		void setDy(float dy)
		{
			this->dy = dy;
		}
	};
#endif /* GAME_H */

