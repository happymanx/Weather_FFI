/*
 *
 *  Copyright (C) 2002-2021, OFFIS e.V.
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation were developed by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module:  dcmdata
 *
 *  Author:  Joerg Riesmeier
 *
 *  Purpose: Interface of class DcmOtherFloat
 *
 */


#ifndef DCVROF_H
#define DCVROF_H

#include "osconfig.h"    /* make sure OS specific configuration is included first */

#include "dcvrfl.h"


// forward declarations
class DcmJsonFormat;


/** a class representing the DICOM value representation 'Other Float' (OF)
 */
class DCMTK_DCMDATA_EXPORT DcmOtherFloat
  : public DcmFloatingPointSingle
{

 public:

    /** constructor.
     *  Create new element from given tag and length.
     *  @param tag DICOM tag for the new element
     *  @param len value length for the new element
     */
    DcmOtherFloat(const DcmTag &tag,
                  const Uint32 len = 0);

    /** copy constructor
     *  @param old element to be copied
     */
    DcmOtherFloat(const DcmOtherFloat &old);

    /** destructor
     */
    virtual ~DcmOtherFloat();

    /** assignment operator
     *  @param obj element to be assigned/copied
     *  @return reference to this object
     */
    DcmOtherFloat &operator=(const DcmOtherFloat &obj);

    /** clone method
     *  @return deep copy of this object
     */
    virtual DcmObject *clone() const
    {
      return new DcmOtherFloat(*this);
    }

    /** Virtual object copying. This method can be used for DcmObject
     *  and derived classes to get a deep copy of an object. Internally
     *  the assignment operator is called if the given DcmObject parameter
     *  is of the same type as "this" object instance. If not, an error
     *  is returned. This function permits copying an object by value
     *  in a virtual way which therefore is different to just calling the
     *  assignment operator of DcmElement which could result in slicing
     *  the object.
     *  @param rhs - [in] The instance to copy from. Has to be of the same
     *                class type as "this" object
     *  @return EC_Normal if copying was successful, error otherwise
     */
    virtual OFCondition copyFrom(const DcmObject& rhs);

    /** get element type identifier
     *  @return type identifier of this class (EVR_OF)
     */
    virtual DcmEVR ident() const;

    /** check whether stored value conforms to the VR and to the specified VM
     *  @param vm parameter not used for this VR
     *  @param oldFormat parameter not used for this VR (only for DA, TM)
     *  @return always returns EC_Normal, i.e. currently no checks are performed
     */
    virtual OFCondition checkValue(const OFString &vm = "",
                                   const OFBool oldFormat = OFFalse);

    /** get value multiplicity
     *  @return always returns 1 (according to the DICOM standard)
     */
    virtual unsigned long getVM();

    /** write object in XML format to a stream
     *  @param out output stream to which the XML document is written
     *  @param flags optional flag used to customize the output (see DCMTypes::XF_xxx)
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition writeXML(STD_NAMESPACE ostream &out,
                                 const size_t flags = 0);

    /** write object in JSON format to a stream
     *  @param out output stream to which the JSON document is written
     *  @param format used to format and customize the output
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition writeJson(STD_NAMESPACE ostream &out,
                                  DcmJsonFormat &format);

    /** create an empty Float32 array of given number of float values and set it.
     *  All array elements are initialized with a value of 0 (using 'memset').
     *  @param numFloats number of float values (32 bit) to be created
     *  @param floatVals stores the pointer to the resulting Float32 array
     *    (set to NULL in case of error)
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition createFloat32Array(const Uint32 numFloats,
                                           Float32 *&floatVals);


};


#endif // DCVROF_H
