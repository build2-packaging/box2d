/* Public API smoke test for libbox2d. */

#include <box2d/box2d.h>
#include <box2d/math_functions.h>

#undef NDEBUG
#include <assert.h>
#include <stdio.h>

int main (void)
{
  b2WorldDef world_def = b2DefaultWorldDef ();
  world_def.gravity = (b2Vec2){0.0f, -10.0f};

  b2WorldId world = b2CreateWorld (&world_def);
  assert (b2World_IsValid (world));

  b2BodyDef ground_def = b2DefaultBodyDef ();
  ground_def.position = (b2Vec2){0.0f, -10.0f};
  b2BodyId ground = b2CreateBody (world, &ground_def);
  assert (b2Body_IsValid (ground));

  b2Polygon ground_box = b2MakeBox (50.0f, 10.0f);
  b2ShapeDef ground_shape_def = b2DefaultShapeDef ();
  b2CreatePolygonShape (ground, &ground_shape_def, &ground_box);

  b2BodyDef body_def = b2DefaultBodyDef ();
  body_def.type = b2_dynamicBody;
  body_def.position = (b2Vec2){0.0f, 4.0f};
  b2BodyId body = b2CreateBody (world, &body_def);
  assert (b2Body_IsValid (body));

  b2Polygon box = b2MakeBox (1.0f, 1.0f);
  b2ShapeDef shape_def = b2DefaultShapeDef ();
  shape_def.density = 1.0f;
  b2CreatePolygonShape (body, &shape_def, &box);

  for (int i = 0; i < 60; ++i)
    b2World_Step (world, 1.0f / 60.0f, 4);

  b2Vec2 p = b2Body_GetPosition (body);
  printf ("smoke position: %f %f\n", (double)p.x, (double)p.y);

  /* Dynamic body should have fallen toward the ground. */
  assert (p.y < 4.0f);

  b2DestroyWorld (world);
  return 0;
}
