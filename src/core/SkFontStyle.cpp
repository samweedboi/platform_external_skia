/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkFontStyle.h"
#include "SkTypeface.h"
#include "SkTypes.h"

SkFontStyle::SkFontStyle() {
    fUnion.fU32 = 0;
    fUnion.fR.fWeight = kNormal_Weight;
    fUnion.fR.fWidth = kNormal_Width;
    fUnion.fR.fSlant = kUpright_Slant;
}

/*static*/SkFontStyle SkFontStyle::FromOldStyle(unsigned oldStyle) {
    return SkFontStyle((oldStyle & SkTypeface::kBold) ? SkFontStyle::kBold_Weight
                                                      : SkFontStyle::kNormal_Weight,
                       SkFontStyle::kNormal_Width,
                       (oldStyle & SkTypeface::kItalic) ? SkFontStyle::kItalic_Slant
                                                        : SkFontStyle::kUpright_Slant);
}
