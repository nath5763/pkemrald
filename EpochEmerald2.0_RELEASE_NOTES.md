# Pokémon Epoch Emerald 2.0

**Release date:** August 19, 2026  
**Patch:** `EpochEmerald2.0.ups`  
**Format:** UPS ROM patch

Epoch Emerald 2.0 expands the game with configurable challenge modes, modern battle mechanics, a complete Fairy-type implementation, new Pokémon and items, smarter opponents, day/night lighting, extensive balance changes, and new postgame content.

## Patch Requirements

Apply `EpochEmerald2.0.ups` to a clean Pokémon Emerald (USA) ROM with this SHA-1 checksum:

```text
f3ae088181bf583e55daf962a92bb46f4f1d07b7
```

A UPS-compatible patcher such as NUPS can be used. Distribute the UPS patch, not a pre-patched ROM.

Because 2.0 changes progression, encounters, trainer data, and save-backed options, starting a new save is recommended.

## Highlights

- Five configurable gameplay modes in a redesigned, scrollable Options menu
- Full Fairy-type support and five Fairy moves
- Four additional Pokémon and expanded evolution families
- Modern held items, abilities, and battle mechanics
- Smarter trainer AI and extensively rebuilt trainer teams
- Accelerated day/night cycle with outdoor lighting
- New Champion's Club daily postgame battles
- Rebuilt Match Call, Wally, and Gym Leader rematches
- Large-scale encounter, map, learnset, and balance updates

## Gameplay Options and Challenge Modes

The Options menu now scrolls to support the following persistent settings:

### Random Starters

Replaces the normal starter choices with three distinct random Pokémon. Eligible starters have a base-stat total below 320.

### Catch-up EXP

Pokémon below the current reference level receive bonus experience. The bonus scales with the number of levels they are behind and is enabled by default on new saves.

### Team EXP Share

Distributes battle experience to otherwise eligible party members. Catch-up EXP and Level Cap calculations continue to be applied separately to each Pokémon.

### Level Cap

Prevents Pokémon from gaining experience beyond the current progression cap. Caps follow the strongest Pokémon belonging to the next major opponent:

1. Roxanne
2. Brawly
3. Wattson
4. Flannery
5. Norman
6. Winona
7. Tate and Liza
8. Juan
9. Leaf
10. Wallace

The cap is removed after Wallace is defeated. Level Cap is enabled by default on new saves.

### Permadeath

Eligible Pokémon that faint are retired after battle and removed from the active party. Retired Pokémon are recorded in the read-only Memorial PC, which displays their nickname, species, level, and gender.

## Pokémon, Types, Moves, and Abilities

### New Pokémon

- Budew
- Munchlax
- Rhyperior
- Bonsly

Their graphics, Pokédex entries, learnsets, encounters, and evolution paths have been integrated into the game.

### Fairy Type

Fairy is now supported by battles, Pokédex searches, summary screens, move displays, species data, and the type chart.

The following evolutionary families received Fairy typing where appropriate:

- Cleffa, Clefairy, and Clefable
- Igglybuff, Jigglypuff, and Wigglytuff
- Mr. Mime
- Togepi, Togetic, and Togekiss
- Azurill, Marill, and Azumarill
- Snubbull and Granbull
- Mawile
- Ralts, Kirlia, and Gardevoir

### New Moves

- Fairy Wind
- Disarming Voice
- Draining Kiss
- Play Rough
- Moonblast
- Incinerate
- Bulldoze
- Stone Edge

### New Abilities

- Scrappy
- Desert Guard
- Sharpness

Numerous existing Pokémon also received adjustments to their stats, typing, abilities, evolution levels, and level-up learnsets. Omastar now has the following base stats:

```text
HP 80 / Attack 50 / Defense 125 / Speed 55 / Sp. Atk 115 / Sp. Def 90
```

## Items and Field Improvements

### New and Updated Items

- **Fly Tool:** Replaces the Fly HM reward with a reusable Key Item.
- **Nature Candy:** Changes a Pokémon to a different random nature while preserving its gender and ability slot.
- **Ability Capsule:** Switches between a species' two available abilities.
- **Light Clay:** Extends Reflect and Light Screen from five turns to eight.
- **Choice Specs:** Boosts Special Attack but locks the holder into one move.
- **Choice Scarf:** Boosts Speed but locks the holder into one move.
- **Life Orb:** Boosts move damage at the cost of recoil after successful attacks.
- **Razor Claw:** Raises the holder's critical-hit ratio.

### Quality-of-Life Changes

- Repel expiration now offers to use another Repel of the same type.
- Players can switch between Mach and Acro Bike modes while riding.
- Running is permitted on maps that previously disabled it.
- Added a Leftovers pickup on Route 135.
- Added a multi-move Punch tutor.

## Battles, Trainers, and Rematches

### Smarter Battle AI

Advanced opponents can now make better decisions based on:

- Estimated incoming and outgoing damage
- Potential knockouts and survivability
- Type matchups and immunities
- Setup moves and current stat stages
- Status and confusion redundancy
- Weather benefits for both teams
- Better switch candidates and threatened Pokémon

Trainer data now supports forcing a specific ability slot for individual party members. Major opponents—including the Elite Four, Wallace, Leaf, and other late-game trainers—received revised teams, movesets, held items, abilities, battle formats, and AI settings.

### Rebuilt Rematches

- Rebuilt all 64 ordinary Match Call trainer progressions from their original Pokémon lineages.
- Original lineages evolve one stage for the first rematch and reach their final forms from the second rematch onward.
- Existing branch evolutions and rematch-only bonus Pokémon are preserved.
- Every ordinary rematch Pokémon gained 10 levels over its previous rematch level.
- Wally's protected Victory Road encounter remains unchanged; his later rematches follow the new lineage rules and gained 10 levels.
- Gym Leader rematches now use their established final compositions:
  - Rematch 1: four Pokémon at level 70
  - Rematch 2: five Pokémon at level 75
  - Rematch 3: six Pokémon at level 80
  - Rematch 4: six Pokémon at level 85

Wild encounter tables and many ordinary trainer parties have also received extensive balancing changes.

## World and Postgame

### Day and Night

- The in-game clock advances at six times real-world speed.
- Outdoor towns, cities, routes, and ocean routes receive dawn, daytime, dusk, and nighttime lighting.
- Lighting transitions gradually around dawn and dusk.

### Champion's Club

- Added a second Champion's Club floor.
- Four opponents appear each in-game day.
- The rotating roster includes Gym Leaders, Elite Four members, Wallace, Steven, Leaf, and the opposite player character.
- Daily victories are tracked separately and reset when the roster changes.

### Maps and Progression

- Revised Champion's Club and Route 135 content.
- Updated Reservoir Cave and its region-map labeling.
- Updated Galadria Gym encounters and progression.
- Revised portions of Ever Grande City, Lavaridge, Route 114, Route 119, Route 128, Route 134, and Route 135.
- Adjusted several healing locations, item placements, event scripts, and story triggers.

## Documentation

The release includes updated reference material:

- Pokédex guide
- Encounter guide
- Gym Leader guide
- Type chart

## Technical Verification

- Full ROM build completed successfully with `wsl make -j4`.
- Trainer-party data audit passed for all ordinary trainers, Wally, and all eight Gym Leaders.
- Protected original parties and out-of-scope special parties remained unchanged during the rematch rebuild.
- Repository whitespace validation passed with `git diff --check`.
