/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmPropertyDefinition_h
#define cmPropertyDefinition_h

#include "cmConfigure.h" // IWYU pragma: keep

#include <string>

#include "cmProperty.h"

/** \class cmPropertyDefinition
 * \brief Property meta-information
 *
 * This class contains the following meta-information about property:
 * - Name;
 * - Various documentation strings;
 * - The scope of the property;
 * - If the property is chained.
 */
class cmPropertyDefinition
{
public:
  /// Constructor
  cmPropertyDefinition(std::string name, cmProperty::ScopeType scope,
                       std::string ShortDescription,
                       std::string FullDescription, bool chained = false);

  /// Is the property chained?
  bool IsChained() const { return this->Chained; }

  /// Get the scope
  cmProperty::ScopeType GetScope() const { return this->Scope; }

  /// Get the documentation (short version)
  const std::string& GetShortDescription() const
  {
    return this->ShortDescription;
  }

  /// Get the documentation (full version)
  const std::string& GetFullDescription() const
  {
    return this->FullDescription;
  }

protected:
  std::string Name;
  std::string ShortDescription;
  std::string FullDescription;
  cmProperty::ScopeType Scope;
  bool Chained;
};

#endif
