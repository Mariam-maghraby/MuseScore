/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __MUSEDATA_H__
#define __MUSEDATA_H__

#include "engraving/types/fraction.h"

namespace mu::engraving {
class Staff;
class Part;
class Score;
class ChordRest;
class Measure;
class Slur;
}

namespace mu::iex::musedata {
//---------------------------------------------------------
//   MuseData
//    used importing Musedata files
//---------------------------------------------------------

class MuseData
{
    int _division;
    engraving::Fraction curTick;
    QList<QStringList> parts;
    engraving::Score* score;
    engraving::ChordRest* chordRest;
    int ntuplet;
    engraving::Measure* measure;
    int voice;
    engraving::Slur* slur[4];

    void musicalAttribute(QString s, engraving::Part*);
    void readPart(QStringList sl, engraving::Part*);
    void readNote(engraving::Part*, const QString& s);
    void readChord(engraving::Part*, const QString& s);
    void readRest(engraving::Part*, const QString& s);
    void readBackup(const QString& s);
    engraving::Measure* createMeasure();
    int countStaves(const QStringList& sl);
    void openSlur(int idx, const engraving::Fraction& tick, engraving::Staff* staff, int voice);
    void closeSlur(int idx, const engraving::Fraction& tick, engraving::Staff* staff, int voice);
    QString diacritical(QString);

public:
    MuseData(engraving::Score* s) { score = s; }
    bool read(const QString&);
    void convert();
};
} // namespace Ms
#endif
