# Pokémon Epoch Emerald: Version 2.0 to 2.1

This document summarizes the gameplay and repository changes in Epoch Emerald 2.1 compared with version 2.0.

## Features

### New Pokémon and Evolutions

- Added Leafeon and Glaceon, increasing the obtainable roster from 404 to 406 Pokémon.
- Added complete front and back sprites, icons, footprints, normal and shiny palettes, overworld graphics, cries, Pokédex data, animations, level-up moves, TM compatibility, and tutor compatibility for both Pokémon.
- Eevee now supports all seven available evolution branches:
  - Vaporeon with a Water Stone.
  - Jolteon with a Thunder Stone.
  - Flareon with a Fire Stone.
  - Espeon through daytime friendship.
  - Umbreon through nighttime friendship.
  - Leafeon with a Leaf Stone.
  - Glaceon with an Ice Stone.

#### Leafeon

- Type: Grass
- Ability: Leaf Guard
- Base stats: `65 HP / 110 Atk / 130 Def / 95 Spe / 60 SpA / 65 SpD`

#### Glaceon

- Type: Ice
- Ability: Snow Cloak
- Base stats: `65 HP / 60 Atk / 110 Def / 65 Spe / 130 SpA / 95 SpD`

### New Item and Ability

#### Ice Stone

- Added as a usable evolution stone with its own icon and description.
- Price: ₽2,100.
- Available as an item-ball pickup in Glacier Hollow.
- Also sold by the second clerk on Lilycove Department Store 2F.
- Evolves Eevee into Glaceon.

#### Leaf Guard

- Added as Leafeon's ability.
- Prevents major status conditions while harsh sunlight is active.
- Also prevents sleep applied directly by moves and delayed sleep from Yawn.

### Pokédex and Completion Progression

- Expanded the Regional Pokédex from the original 202-species Hoenn listing to all 406 obtainable Pokémon, ending with Leafeon and Glaceon.
- Enabled the complete National Pokédex view as soon as the player receives the Pokédex.
- Changed Birch's Pokédex ratings to advance in 20-species intervals instead of 10-species intervals.
- Full completion now requires all 406 species, including Jirachi, Deoxys, Leafeon, and Glaceon.
- Kept the persisted Pokédex flag storage at 54 bytes, retaining save-layout compatibility while supporting up to 432 entries.

### Extended Level Cap Progression

The optional Level Cap now continues through the Champion's Club postgame instead of ending after Wallace.

| Progression point | Level cap |
| --- | ---: |
| Before defeating Steven | 78 |
| After Steven, before Ben | 78 |
| After Ben, before Ryan | 82 |
| After Ryan, before Angie | 87 |
| After Angie, before Sirus | 92 |
| After Sirus | 100 / removed |

Ben's team is level 77, but the cap intentionally remains at 78 so defeating Steven cannot lower the established cap.

### Pokémon Balance Changes

Stats are listed as `HP / Atk / Def / Spe / SpA / SpD`.

| Pokémon | 2.0 | 2.1 |
| --- | --- | --- |
| Claydol | `60 / 70 / 105 / 75 / 70 / 120` | `60 / 60 / 105 / 75 / 80 / 120` |
| Cacturne | `70 / 115 / 80 / 55 / 115 / 80` | `85 / 115 / 90 / 55 / 80 / 90` |
| Medicham | `60 / 60 / 80 / 80 / 60 / 80` | `60 / 60 / 80 / 80 / 90 / 80` |
| Altaria | `80 / 70 / 100 / 80 / 70 / 100` | `100 / 70 / 100 / 80 / 70 / 100` |
| Swalot | `100 / 53 / 88 / 55 / 83 / 88` | `100 / 50 / 90 / 55 / 85 / 90` |
| Exploud | `105 / 95 / 70 / 70 / 90 / 70` | `105 / 75 / 80 / 70 / 90 / 70` |
| Huntail | `75 / 104 / 105 / 52 / 94 / 95` | `75 / 104 / 105 / 72 / 74 / 95` |
| Gorebyss | `75 / 80 / 105 / 50 / 115 / 95` | `75 / 60 / 105 / 70 / 115 / 95` |

- Zangoose now has Sharpness in its second ability slot. Its primary ability remains Immunity.

### Encounters and World Changes

- Added land, water, and fishing encounter tables to Littleroot Town.
- Updated layouts in Littleroot Town, Route 135, and the Champion's Club.
- Added the Ice Stone pickup to Glacier Hollow.

Littleroot Town's encounter pool includes:

- **Land:** Mankey, Rattata, Poliwag, Pidgey, Snorunt, Zangoose, Totodile, Budew, and Dratini.
- **Water:** Horsea, Golduck, and Feebas.
- **Fishing:** Clamperl, Magikarp, Shellder, Crawdaunt, Feebas, Gyarados, and Dragonair.

### Repository and Release Support

- Added a GitHub Actions workflow for collecting release-download metrics.
- Added the release-metrics collection script and automated tests.
- Updated the project README, 2.0 release notes, Pokédex guide, and UPS release artifacts for the current project state.
- Removed obsolete Spec Kit/Copilot/Gemini scaffolding and the superseded 1.2 UPS patch from the repository.

## Bug Fixes

### Battle Style Option

- Fixed normal trainer battles ignoring the player's Shift/Set selection.
- Normal trainers now use the battle style saved in the Options menu.
- Trainers explicitly tagged as Set battles continue to force Set mode, even when the player selects Shift.
- Wild and other non-trainer battles retain their existing behavior.

### Learnsets and Pokémon Presentation

- **Cacturne:** Night Slash now correctly replaces Shadow Claw at level 53.
- **Medicham:** now learns Psychic at level 40 and Psych Up at level 46; the former level 46 Reversal and level 48 Zen Headbutt entries were removed.
- **Exploud:** now learns Extrasensory at level 69.
- **Huntail:** now learns Protect at level 33, Body Slam at level 50, and Ice Fang at level 55; Hydro Pump was removed from level 50.
- Added dedicated animated front-sprite registrations for Budew, Munchlax, Bonsly, and Rhyperior instead of reusing their evolved or pre-evolved species' animation data.
- Corrected Munchlax's front animation ID and back animation assignment.
- Corrected the associated graphics declarations, sprite tables, coordinates, footprints, and palette registrations for the affected added Pokémon.

### Pokédex and Save Progression

- Corrected the Pokédex rating text that referred to the `100-kind mark`; it now says `200-kind mark`.
- Fixed completion checks that previously excluded Jirachi and Deoxys.
- Removed the obsolete Hall of Fame National Pokédex-upgrade scene.
- Added migration handling for existing saves waiting on the removed upgrade scene, advancing them to the completion-reward state.
- Correctly initializes Scott's Battle Frontier call progression when the old Pokédex-upgrade state is skipped.
- Fixed Anabel's Mossdeep Space Center event to check whether the player has received the Pokédex instead of checking the removed National Pokédex gate.

### Champion's Club and Map Fixes

- Fixed Sirus's Champion's Club event starting Angie's battle instead of Sirus's battle.
- Corrected the Champion's Club region-map label, which previously displayed `RESERVOIR CAVE`.

## Save Guidance

Because 2.1 changes Pokédex state, completion requirements, encounters, maps, and postgame progression, starting a new save is recommended. Players continuing an existing save should make a backup first.
