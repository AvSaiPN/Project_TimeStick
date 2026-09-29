# Project TimeStick
An offline, physical, time-management Tool for students. 

# Current Status: 
  September 29th, 2026:  Currently working on V0, with an expected date of completion (for this prototype) of January First, 2027. Should help with your New Year Resolutions.

# V0  - a basic physical timer prototype powered by USB using an Arduino Nano
  ### Software:
  - count-up logic
  - increment/decrement functions
  - pause/resume and reset
  - function for minute/second swapping when setting a timer (also for menu adjustment in later versions)
    
  ### Hardware:
  - buttons (primarily microswitches harvested from old mice)
  - 16x2 LCD (with a soldered I2C backpack)
  - Arduino Nano (for compactness)
  - A whole lotta wires
  
  ### Enclosure: 
  I plan on using a homemade Starlite mix, reinforced by card and plastic (both recycled) for the enclosure, because why not

  ### Documentation:
  - I've been maintaining a Project Journal so you can go through the creation process if interested. However, I'm using a Google Doc for now, so it's likely I'll be uploading it to my website (once I make it) as well as status updates on my projects. 
  - HOWEVER, I will be uploading a Project Report to this repo upon the completion of every version. The current version is V0.2 as of September 29th 2026 (0.1 was retired due to insufficient software modularity leading to difficult expansion and further development a couple of months earlier). It is likely that V0.2 will be the version that becomes V0, as things are looking good for now.

# Design Goals
Basically, it's meant to help with anything that has to do with measuring time, such as Pomodoros, Stopwatch, Custom Timers, Staggered Timers (For workout sessions), etc. Probably won't include an Alarm mode. 
1. Portability: as the name implies, it's shaped like a 15 cm (or smaller) Stick for portability, so you can just toss it into your bag or pencil case.
2. Low-Cost: I plan on using cheap components for all the versions because it's meant to be an easily obtainable (or creatable) study tool. This ain't some luxury gizmo.
3. Low-Profile: Students often have to study in weird places (and not-so-weird ones), and often, a timer with a loud noise signalling the end of a session would be inconvenient. Same with brightly colored, tropical-themed, strobe-like sticks. Hence, I will primarily be using simple colors with slight accents at most (a hazard theme might look cool here).
4. Modularity: if you're a DIY enthusiast or an engineering student, there is no reason why you shouldn't be able to make your own version of this gizmo. But I'm aware not everyone has the time or ability to dedicate hours and days to building one from scratch, so I'm doing my best to keep the software (just the software for now) as modular as can be, so you can learn and modify the code as you wish without breaking the entire project.
  5. Ecosystem/Future Projects: I plan on making more stuff like this, so it would be nice for them to be cohesive and support each other. I'm not changing the offline nature though. Only the uses would be complementary. 
