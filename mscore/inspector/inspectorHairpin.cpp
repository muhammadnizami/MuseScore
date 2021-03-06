//=============================================================================
//  MuseScore
//  Music Composition & Notation
//  $Id:$
//
//  Copyright (C) 2012 Werner Schweer
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENSE.GPL
//=============================================================================

#include "inspectorHairpin.h"
#include "musescore.h"
#include "libmscore/hairpin.h"
#include "libmscore/score.h"

namespace Ms {

//---------------------------------------------------------
//   InspectorHairpin
//---------------------------------------------------------

InspectorHairpin::InspectorHairpin(QWidget* parent)
   : InspectorElementBase(parent)
      {
      l.setupUi(addWidget());
      setupLineStyle(l.lineStyle);
      h.setupUi(addWidget());

      h.hairpinType->clear();
      h.hairpinType->addItem(tr("Crescendo Hairpin"),   int(Hairpin::Type::CRESC_HAIRPIN));
      h.hairpinType->addItem(tr("Decrescendo Hairpin"), int(Hairpin::Type::DECRESC_HAIRPIN) );
      h.hairpinType->addItem(tr("Crescendo Line"),      int(Hairpin::Type::CRESC_LINE));
      h.hairpinType->addItem(tr("Decrescendo Line"),    int(Hairpin::Type::DECRESC_LINE));

      std::vector<InspectorItem> il = {
            { P_ID::DIAGONAL,            0, 0, l.diagonal,          l.resetDiagonal          },
            { P_ID::LINE_VISIBLE,        0, 0, l.lineVisible,       l.resetLineVisible       },
            { P_ID::LINE_COLOR,          0, 0, l.lineColor,         l.resetLineColor         },
            { P_ID::LINE_WIDTH,          0, 0, l.lineWidth,         l.resetLineWidth         },
            { P_ID::LINE_STYLE,          0, 0, l.lineStyle,         l.resetLineStyle         },
            { P_ID::HAIRPIN_CIRCLEDTIP,  0, 0, h.hairpinCircledTip, h.resetHairpinCircledTip },
            { P_ID::HAIRPIN_TYPE,        0, 0, h.hairpinType,       h.resetHairpinType       },
            { P_ID::DYNAMIC_RANGE,       0, 0, h.dynRange,          h.resetDynRange          },
            { P_ID::VELO_CHANGE,         0, 0, h.veloChange,        h.resetVeloChange        },
            { P_ID::HAIRPIN_HEIGHT,      0, 0, h.hairpinHeight,     h.resetHairpinHeight     },
            { P_ID::HAIRPIN_CONT_HEIGHT, 0, 0, h.hairpinContHeight, h.resetHairpinContHeight }
            };
      mapSignals(il);
      }

//---------------------------------------------------------
//   postInit
//---------------------------------------------------------

void InspectorHairpin::postInit()
      {
      bool useTextLine = h.hairpinType->currentIndex() == int(Hairpin::Type::CRESC_LINE)
         || h.hairpinType->currentIndex() == int(Hairpin::Type::DECRESC_LINE);
      l.lineVisible->setEnabled(useTextLine);
      h.hairpinCircledTip->setDisabled(useTextLine);
      h.hairpinHeight->setDisabled(useTextLine);
      h.hairpinContHeight->setDisabled(useTextLine);
      }

}

