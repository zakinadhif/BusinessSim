Goals:
 - Animation
 - Entity
 - Component
 - System
 - States
 - Input
 - GUI, uses ImGui and TGUI

Requirements:
# General
 - System is updated each frame by the state owning it.
 - Entity's component is updated by system or a script component.
   for example:
   an entity A have a physics or rigid body component.
   then a physics system is updating the entities that have a rigid body component.
   or
   an entity A have a script component.
   then a script system is running or executing the script in each frame.

# Input
 - Input is a system, may be named "InputSystem"
 - Input system is updated by the state in each frame
 - A state or an entity can register an action into action map in input system
 - A state or an entity can register an action callback into input system by saying for ex.
   `inputSystem.actionSystem.connect('shoot', &onShoot)`

# GUI
 - GUI are handled by the game state instead of the game itself

# Animation
 - Animation is a system

# Entity
# State
