﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/xray/model/ErrorRootCauseEntity.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace XRay
{
namespace Model
{

ErrorRootCauseEntity::ErrorRootCauseEntity() : 
    m_nameHasBeenSet(false),
    m_exceptionsHasBeenSet(false),
    m_remote(false),
    m_remoteHasBeenSet(false)
{
}

ErrorRootCauseEntity::ErrorRootCauseEntity(JsonView jsonValue) : 
    m_nameHasBeenSet(false),
    m_exceptionsHasBeenSet(false),
    m_remote(false),
    m_remoteHasBeenSet(false)
{
  *this = jsonValue;
}

ErrorRootCauseEntity& ErrorRootCauseEntity::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Exceptions"))
  {
    Array<JsonView> exceptionsJsonList = jsonValue.GetArray("Exceptions");
    for(unsigned exceptionsIndex = 0; exceptionsIndex < exceptionsJsonList.GetLength(); ++exceptionsIndex)
    {
      m_exceptions.push_back(exceptionsJsonList[exceptionsIndex].AsObject());
    }
    m_exceptionsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Remote"))
  {
    m_remote = jsonValue.GetBool("Remote");

    m_remoteHasBeenSet = true;
  }

  return *this;
}

JsonValue ErrorRootCauseEntity::Jsonize() const
{
  JsonValue payload;

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", m_name);

  }

  if(m_exceptionsHasBeenSet)
  {
   Array<JsonValue> exceptionsJsonList(m_exceptions.size());
   for(unsigned exceptionsIndex = 0; exceptionsIndex < exceptionsJsonList.GetLength(); ++exceptionsIndex)
   {
     exceptionsJsonList[exceptionsIndex].AsObject(m_exceptions[exceptionsIndex].Jsonize());
   }
   payload.WithArray("Exceptions", std::move(exceptionsJsonList));

  }

  if(m_remoteHasBeenSet)
  {
   payload.WithBool("Remote", m_remote);

  }

  return payload;
}

} // namespace Model
} // namespace XRay
} // namespace Aws
