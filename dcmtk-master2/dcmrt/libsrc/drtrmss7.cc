/*
 *
 *  Copyright (C) 2008-2012, OFFIS e.V. and ICSMED AG, Oldenburg, Germany
 *  Copyright (C) 2013-2017, J. Riesmeier, Oldenburg, Germany
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  Source file for class DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule
 *
 *  Generated automatically from DICOM PS 3.3-2017e
 *  File created on 2017-12-05 09:30:54
 *
 */


#include "dcmtk/config/osconfig.h"     // make sure OS specific configuration is included first

#include "dcmtk/dcmrt/seq/drtrmss7.h"


// --- item class ---

DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::Item(const OFBool emptyDefaultItem)
  : EmptyDefaultItem(emptyDefaultItem),
    RangeModulatorGatingStartValue(DCM_RangeModulatorGatingStartValue),
    RangeModulatorGatingStopValue(DCM_RangeModulatorGatingStopValue),
    ReferencedRangeModulatorNumber(DCM_ReferencedRangeModulatorNumber)
{
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::Item(const Item &copy)
  : EmptyDefaultItem(copy.EmptyDefaultItem),
    RangeModulatorGatingStartValue(copy.RangeModulatorGatingStartValue),
    RangeModulatorGatingStopValue(copy.RangeModulatorGatingStopValue),
    ReferencedRangeModulatorNumber(copy.ReferencedRangeModulatorNumber)
{
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::~Item()
{
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::operator=(const Item &copy)
{
    if (this != &copy)
    {
        EmptyDefaultItem = copy.EmptyDefaultItem;
        RangeModulatorGatingStartValue = copy.RangeModulatorGatingStartValue;
        RangeModulatorGatingStopValue = copy.RangeModulatorGatingStopValue;
        ReferencedRangeModulatorNumber = copy.ReferencedRangeModulatorNumber;
    }
    return *this;
}


void DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::clear()
{
    if (!EmptyDefaultItem)
    {
        /* clear all DICOM attributes */
        ReferencedRangeModulatorNumber.clear();
        RangeModulatorGatingStartValue.clear();
        RangeModulatorGatingStopValue.clear();
    }
}


OFBool DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::isEmpty()
{
    return ReferencedRangeModulatorNumber.isEmpty() &&
           RangeModulatorGatingStartValue.isEmpty() &&
           RangeModulatorGatingStopValue.isEmpty();
}


OFBool DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::isValid() const
{
    return !EmptyDefaultItem;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::read(DcmItem &item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        /* re-initialize object */
        clear();
        getAndCheckElementFromDataset(item, ReferencedRangeModulatorNumber, "1", "1", "RangeModulatorSettingsSequence");
        getAndCheckElementFromDataset(item, RangeModulatorGatingStartValue, "1", "1C", "RangeModulatorSettingsSequence");
        getAndCheckElementFromDataset(item, RangeModulatorGatingStopValue, "1", "1C", "RangeModulatorSettingsSequence");
        result = EC_Normal;
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::write(DcmItem &item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = EC_Normal;
        addElementToDataset(result, item, new DcmIntegerString(ReferencedRangeModulatorNumber), "1", "1", "RangeModulatorSettingsSequence");
        addElementToDataset(result, item, new DcmFloatingPointSingle(RangeModulatorGatingStartValue), "1", "1C", "RangeModulatorSettingsSequence");
        addElementToDataset(result, item, new DcmFloatingPointSingle(RangeModulatorGatingStopValue), "1", "1C", "RangeModulatorSettingsSequence");
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::getRangeModulatorGatingStartValue(Float32 &value, const unsigned long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return OFconst_cast(DcmFloatingPointSingle &, RangeModulatorGatingStartValue).getFloat32(value, pos);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::getRangeModulatorGatingStopValue(Float32 &value, const unsigned long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return OFconst_cast(DcmFloatingPointSingle &, RangeModulatorGatingStopValue).getFloat32(value, pos);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::getReferencedRangeModulatorNumber(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(ReferencedRangeModulatorNumber, value, pos);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::getReferencedRangeModulatorNumber(Sint32 &value, const unsigned long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return OFconst_cast(DcmIntegerString &, ReferencedRangeModulatorNumber).getSint32(value, pos);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::setRangeModulatorGatingStartValue(const Float32 value, const unsigned long pos)
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return RangeModulatorGatingStartValue.putFloat32(value, pos);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::setRangeModulatorGatingStopValue(const Float32 value, const unsigned long pos)
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return RangeModulatorGatingStopValue.putFloat32(value, pos);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item::setReferencedRangeModulatorNumber(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmIntegerString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = ReferencedRangeModulatorNumber.putOFStringArray(value);
    }
    return result;
}


// --- sequence class ---

DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule(const OFBool emptyDefaultSequence)
  : EmptyDefaultSequence(emptyDefaultSequence),
    SequenceOfItems(),
    CurrentItem(),
    EmptyItem(OFTrue /*emptyDefaultItem*/)
{
    CurrentItem = SequenceOfItems.end();
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule(const DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule &copy)
  : EmptyDefaultSequence(copy.EmptyDefaultSequence),
    SequenceOfItems(),
    CurrentItem(),
    EmptyItem(OFTrue /*emptyDefaultItem*/)
{
    /* create a copy of the internal sequence of items */
    Item *item = NULL;
    OFListConstIterator(Item *) current = copy.SequenceOfItems.begin();
    const OFListConstIterator(Item *) last = copy.SequenceOfItems.end();
    while (current != last)
    {
        item = new Item(**current);
        if (item != NULL)
        {
            SequenceOfItems.push_back(item);
        } else {
            /* memory exhausted, there is nothing we can do about it */
            break;
        }
        ++current;
    }
    CurrentItem = SequenceOfItems.begin();
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::operator=(const DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule &copy)
{
    if (this != &copy)
    {
        clear();
        EmptyDefaultSequence = copy.EmptyDefaultSequence;
        /* create a copy of the internal sequence of items */
        Item *item = NULL;
        OFListConstIterator(Item *) current = copy.SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = copy.SequenceOfItems.end();
        while (current != last)
        {
            item = new Item(**current);
            if (item != NULL)
            {
                SequenceOfItems.push_back(item);
            } else {
                /* memory exhausted, there is nothing we can do about it */
                break;
            }
            ++current;
        }
        CurrentItem = SequenceOfItems.begin();
    }
    return *this;
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::~DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule()
{
    clear();
}


void DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::clear()
{
    if (!EmptyDefaultSequence)
    {
        CurrentItem = SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = SequenceOfItems.end();
        /* delete all items and free memory */
        while (CurrentItem != last)
        {
            delete (*CurrentItem);
            CurrentItem = SequenceOfItems.erase(CurrentItem);
        }
        /* make sure that the list is empty */
        SequenceOfItems.clear();
        CurrentItem = SequenceOfItems.end();
    }
}


OFBool DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::isEmpty()
{
    return SequenceOfItems.empty();
}


OFBool DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::isValid() const
{
    return !EmptyDefaultSequence;
}


size_t DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::getNumberOfItems() const
{
    return SequenceOfItems.size();
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::gotoFirstItem()
{
    OFCondition result = EC_IllegalCall;
    if (!SequenceOfItems.empty())
    {
        CurrentItem = SequenceOfItems.begin();
        result = EC_Normal;
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::gotoNextItem()
{
    OFCondition result = EC_IllegalCall;
    if (CurrentItem != SequenceOfItems.end())
    {
        ++CurrentItem;
        result = EC_Normal;
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::gotoItem(const size_t num, OFListIterator(Item *) &iterator)
{
    OFCondition result = EC_IllegalCall;
    if (!SequenceOfItems.empty())
    {
        size_t idx = num + 1;
        iterator = SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = SequenceOfItems.end();
        while ((--idx > 0) && (iterator != last))
            ++iterator;
        /* specified list item found? */
        if ((idx == 0) && (iterator != last))
            result = EC_Normal;
        else
            result = EC_IllegalParameter;
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::gotoItem(const size_t num, OFListConstIterator(Item *) &iterator) const
{
    OFCondition result = EC_IllegalCall;
    if (!SequenceOfItems.empty())
    {
        size_t idx = num + 1;
        iterator = SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = SequenceOfItems.end();
        while ((--idx > 0) && (iterator != last))
            ++iterator;
        /* specified list item found? */
        if ((idx == 0) && (iterator != last))
            result = EC_Normal;
        else
            result = EC_IllegalParameter;
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::gotoItem(const size_t num)
{
    return gotoItem(num, CurrentItem);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::getCurrentItem(Item *&item) const
{
    OFCondition result = EC_IllegalCall;
    if (CurrentItem != SequenceOfItems.end())
    {
        item = *CurrentItem;
        result = EC_Normal;
    }
    return result;
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::getCurrentItem()
{
    if (CurrentItem != SequenceOfItems.end())
        return **CurrentItem;
    else
        return EmptyItem;
}


const DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::getCurrentItem() const
{
    if (CurrentItem != SequenceOfItems.end())
        return **CurrentItem;
    else
        return EmptyItem;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::getItem(const size_t num, Item *&item)
{
    OFListIterator(Item *) iterator;
    OFCondition result = gotoItem(num, iterator);
    if (result.good())
        item = *iterator;
    return result;
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::getItem(const size_t num)
{
    OFListIterator(Item *) iterator;
    if (gotoItem(num, iterator).good())
        return **iterator;
    else
        return EmptyItem;
}


const DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::getItem(const size_t num) const
{
    OFListConstIterator(Item *) iterator;
    if (gotoItem(num, iterator).good())
        return **iterator;
    else
        return EmptyItem;
}


DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::operator[](const size_t num)
{
    return getItem(num);
}


const DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::Item &DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::operator[](const size_t num) const
{
    return getItem(num);
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::addItem(Item *&item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        item = new Item();
        if (item != NULL)
        {
            SequenceOfItems.push_back(item);
            result = EC_Normal;
        } else
            result = EC_MemoryExhausted;
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::insertItem(const size_t pos, Item *&item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        OFListIterator(Item *) iterator;
        result = gotoItem(pos, iterator);
        if (result.good())
        {
            item = new Item();
            if (item != NULL)
            {
                SequenceOfItems.insert(iterator, 1, item);
                result = EC_Normal;
            } else
                result = EC_MemoryExhausted;
        } else
            result = addItem(item);
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::removeItem(const size_t pos)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        OFListIterator(Item *) iterator;
        if (gotoItem(pos, iterator).good())
        {
            delete *iterator;
            iterator = SequenceOfItems.erase(iterator);
            result = EC_Normal;
        } else
            result = EC_IllegalParameter;
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::read(DcmItem &dataset,
                                                                                   const OFString &card,
                                                                                   const OFString &type,
                                                                                   const char *moduleName)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        /* re-initialize object */
        clear();
        /* retrieve sequence element from dataset */
        DcmSequenceOfItems *sequence;
        result = dataset.findAndGetSequence(DCM_RangeModulatorSettingsSequence, sequence);
        if (sequence != NULL)
        {
            if (checkElementValue(*sequence, card, type, result, moduleName))
            {
                DcmStack stack;
                OFBool first = OFTrue;
                /* iterate over all sequence items */
                while (result.good() && sequence->nextObject(stack, first /*intoSub*/).good())
                {
                    DcmItem *ditem = OFstatic_cast(DcmItem *, stack.top());
                    if (ditem != NULL)
                    {
                        Item *item = new Item();
                        if (item != NULL)
                        {
                            result = item->read(*ditem);
                            if (result.good())
                            {
                                /* append new item to the end of the list */
                                SequenceOfItems.push_back(item);
                                first = OFFalse;
                            }
                        } else
                            result = EC_MemoryExhausted;
                    } else
                        result = EC_CorruptedData;
                }
            }
        } else {
            DcmSequenceOfItems element(DCM_RangeModulatorSettingsSequence);
            checkElementValue(element, card, type, result, moduleName);
        }
    }
    return result;
}


OFCondition DRTRangeModulatorSettingsSequenceInRTIonBeamsSessionRecordModule::write(DcmItem &dataset,
                                                                                    const OFString &card,
                                                                                    const OFString &type,
                                                                                    const char *moduleName)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        result = EC_MemoryExhausted;
        DcmSequenceOfItems *sequence = new DcmSequenceOfItems(DCM_RangeModulatorSettingsSequence);
        if (sequence != NULL)
        {
            result = EC_Normal;
            /* an empty optional sequence is not written */
            if ((type == "2") || !SequenceOfItems.empty())
            {
                OFListIterator(Item *) iterator = SequenceOfItems.begin();
                const OFListConstIterator(Item *) last = SequenceOfItems.end();
                /* iterate over all sequence items */
                while (result.good() && (iterator != last))
                {
                    DcmItem *item = new DcmItem();
                    if (item != NULL)
                    {
                        /* append new item to the end of the sequence */
                        result = sequence->append(item);
                        if (result.good())
                        {
                            result = (*iterator)->write(*item);
                            ++iterator;
                        } else
                            delete item;
                    } else
                        result = EC_MemoryExhausted;
                }
                if (result.good())
                {
                    /* insert sequence element into the dataset */
                    result = dataset.insert(sequence, OFTrue /*replaceOld*/);
                }
                if (DCM_dcmrtLogger.isEnabledFor(OFLogger::WARN_LOG_LEVEL))
                    checkElementValue(*sequence, card, type, result, moduleName);
                if (result.good())
                {
                    /* forget reference to sequence object (avoid deletion below) */
                    sequence = NULL;
                }
            }
            else if (type == "1")
            {
                /* empty type 1 sequence not allowed */
                result = RT_EC_InvalidValue;
                if (DCM_dcmrtLogger.isEnabledFor(OFLogger::WARN_LOG_LEVEL))
                    checkElementValue(*sequence, card, type, result, moduleName);
            }
            /* delete sequence (if not inserted into the dataset) */
            delete sequence;
        }
    }
    return result;
}


// end of source file
