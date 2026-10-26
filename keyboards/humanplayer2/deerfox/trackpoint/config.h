// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Serial (inter-half) and PS/2 both use PIO; keep them on separate PIO blocks
#define PS2_PIO_USE_PIO1