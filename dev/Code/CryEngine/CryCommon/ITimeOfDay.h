/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.
#pragma once

#include <SerializeFwd.h>


struct SBezierKey;
struct ITimeOfDayUpdateCallback;
struct ISplineInterpolator;


//! Interface to the Time Of Day functionality.
struct ITimeOfDay
{
    enum ETimeOfDayParamID
    {
        PARAM_SUN_COLOR,
        PARAM_SUN_INTENSITY,
        PARAM_SUN_SPECULAR_MULTIPLIER,

        PARAM_FOG_COLOR,
        PARAM_FOG_COLOR_MULTIPLIER,
        PARAM_VOLFOG_HEIGHT,
        PARAM_VOLFOG_DENSITY,
        PARAM_FOG_COLOR2,
        PARAM_FOG_COLOR2_MULTIPLIER,
        PARAM_VOLFOG_HEIGHT2,
        PARAM_VOLFOG_DENSITY2,
        PARAM_VOLFOG_HEIGHT_OFFSET,

        PARAM_FOG_RADIAL_COLOR,
        PARAM_FOG_RADIAL_COLOR_MULTIPLIER,
        PARAM_VOLFOG_RADIAL_SIZE,
        PARAM_VOLFOG_RADIAL_LOBE,

        PARAM_VOLFOG_FINAL_DENSITY_CLAMP,

        PARAM_VOLFOG_GLOBAL_DENSITY,
        PARAM_VOLFOG_RAMP_START,
        PARAM_VOLFOG_RAMP_END,
        PARAM_VOLFOG_RAMP_INFLUENCE,

        PARAM_VOLFOG_SHADOW_DARKENING,
        PARAM_VOLFOG_SHADOW_DARKENING_SUN,
        PARAM_VOLFOG_SHADOW_DARKENING_AMBIENT,
        PARAM_VOLFOG_SHADOW_RANGE,

        PARAM_VOLFOG2_HEIGHT,
        PARAM_VOLFOG2_DENSITY,
        PARAM_VOLFOG2_HEIGHT2,
        PARAM_VOLFOG2_DENSITY2,
        PARAM_VOLFOG2_GLOBAL_DENSITY,
        PARAM_VOLFOG2_RAMP_START,
        PARAM_VOLFOG2_RAMP_END,
        PARAM_VOLFOG2_COLOR1,
        PARAM_VOLFOG2_ANISOTROPIC1,
        PARAM_VOLFOG2_COLOR2,
        PARAM_VOLFOG2_ANISOTROPIC2,
        PARAM_VOLFOG2_BLEND_FACTOR,
        PARAM_VOLFOG2_BLEND_MODE,
        PARAM_VOLFOG2_COLOR,
        PARAM_VOLFOG2_ANISOTROPIC,
        PARAM_VOLFOG2_RANGE,
        PARAM_VOLFOG2_INSCATTER,
        PARAM_VOLFOG2_EXTINCTION,
        PARAM_VOLFOG2_GLOBAL_FOG_VISIBILITY,
        PARAM_VOLFOG2_FINAL_DENSITY_CLAMP,

        PARAM_SKYLIGHT_SUN_INTENSITY,
        PARAM_SKYLIGHT_SUN_INTENSITY_MULTIPLIER,

        PARAM_SKYLIGHT_KM,
        PARAM_SKYLIGHT_KR,
        PARAM_SKYLIGHT_G,

        PARAM_SKYLIGHT_WAVELENGTH_R,
        PARAM_SKYLIGHT_WAVELENGTH_G,
        PARAM_SKYLIGHT_WAVELENGTH_B,

        PARAM_NIGHSKY_HORIZON_COLOR,
        PARAM_NIGHSKY_HORIZON_COLOR_MULTIPLIER,
        PARAM_NIGHSKY_ZENITH_COLOR,
        PARAM_NIGHSKY_ZENITH_COLOR_MULTIPLIER,
        PARAM_NIGHSKY_ZENITH_SHIFT,

        PARAM_NIGHSKY_START_INTENSITY,

        PARAM_NIGHSKY_MOON_COLOR,
        PARAM_NIGHSKY_MOON_COLOR_MULTIPLIER,
        PARAM_NIGHSKY_MOON_INNERCORONA_COLOR,
        PARAM_NIGHSKY_MOON_INNERCORONA_COLOR_MULTIPLIER,
        PARAM_NIGHSKY_MOON_INNERCORONA_SCALE,
        PARAM_NIGHSKY_MOON_OUTERCORONA_COLOR,
        PARAM_NIGHSKY_MOON_OUTERCORONA_COLOR_MULTIPLIER,
        PARAM_NIGHSKY_MOON_OUTERCORONA_SCALE,

        PARAM_CLOUDSHADING_SUNLIGHT_MULTIPLIER,
        PARAM_CLOUDSHADING_SUNLIGHT_CUSTOM_COLOR,
        PARAM_CLOUDSHADING_SUNLIGHT_CUSTOM_COLOR_MULTIPLIER,
        PARAM_CLOUDSHADING_SUNLIGHT_CUSTOM_COLOR_INFLUENCE,

        PARAM_SUN_SHAFTS_VISIBILITY,
        PARAM_SUN_RAYS_VISIBILITY,
        PARAM_SUN_RAYS_ATTENUATION,
        PARAM_SUN_RAYS_SUNCOLORINFLUENCE,
        PARAM_SUN_RAYS_CUSTOMCOLOR,

        PARAM_OCEANFOG_COLOR,            // Remove when ocean related feature toggle is removed.
        PARAM_OCEANFOG_COLOR_MULTIPLIER, // Remove when ocean related feature toggle is removed.
        PARAM_OCEANFOG_DENSITY,          // Remove when ocean related feature toggle is removed.

        PARAM_SKYBOX_MULTIPLIER,

        PARAM_HDR_FILMCURVE_SHOULDER_SCALE,
        PARAM_HDR_FILMCURVE_LINEAR_SCALE,
        PARAM_HDR_FILMCURVE_TOE_SCALE,
        PARAM_HDR_FILMCURVE_WHITEPOINT,

        PARAM_HDR_COLORGRADING_COLOR_SATURATION,
        PARAM_HDR_COLORGRADING_COLOR_BALANCE,

        PARAM_HDR_EYEADAPTATION_SCENEKEY,
        PARAM_HDR_EYEADAPTATION_MIN_EXPOSURE,
        PARAM_HDR_EYEADAPTATION_MAX_EXPOSURE,
        PARAM_HDR_EYEADAPTATION_EV_MIN,
        PARAM_HDR_EYEADAPTATION_EV_MAX,
        PARAM_HDR_EYEADAPTATION_EV_AUTO_COMPENSATION,
        PARAM_HDR_BLOOM_AMOUNT,

        PARAM_COLORGRADING_FILTERS_GRAIN,
        PARAM_COLORGRADING_FILTERS_PHOTOFILTER_COLOR,
        PARAM_COLORGRADING_FILTERS_PHOTOFILTER_DENSITY,

        PARAM_COLORGRADING_DOF_FOCUSRANGE,
        PARAM_COLORGRADING_DOF_BLURAMOUNT,

        PARAM_SHADOWSC0_BIAS,
        PARAM_SHADOWSC0_SLOPE_BIAS,
        PARAM_SHADOWSC1_BIAS,
        PARAM_SHADOWSC1_SLOPE_BIAS,
        PARAM_SHADOWSC2_BIAS,
        PARAM_SHADOWSC2_SLOPE_BIAS,
        PARAM_SHADOWSC3_BIAS,
        PARAM_SHADOWSC3_SLOPE_BIAS,
        PARAM_SHADOWSC4_BIAS,
        PARAM_SHADOWSC4_SLOPE_BIAS,
        PARAM_SHADOWSC5_BIAS,
        PARAM_SHADOWSC5_SLOPE_BIAS,
        PARAM_SHADOWSC6_BIAS,
        PARAM_SHADOWSC6_SLOPE_BIAS,
        PARAM_SHADOWSC7_BIAS,
        PARAM_SHADOWSC7_SLOPE_BIAS,

        PARAM_SHADOW_JITTERING,

        PARAM_HDR_DYNAMIC_POWER_FACTOR,
        PARAM_TERRAIN_OCCL_MULTIPLIER,
        PARAM_SUN_COLOR_MULTIPLIER,

        PARAM_TOTAL
    };

    struct SPresetInfo
    {
        const char* m_pName;
        bool m_bCurrent;
    };

    enum EVariableType
    {
        TYPE_FLOAT,
        TYPE_COLOR
    };
    struct SVariableInfo
    {
        const char* name;  //!< Variable name.
        const char* displayName;  //!< Variable user readable name.
        const char* group; //!< Group name.
        int nParamId;
        EVariableType type;
        float fValue[3];    //!< Value of the variable (3 needed for color type).
        ISplineInterpolator* pInterpolator; //!< Splines that control variable value.
    };
    struct SAdvancedInfo
    {
        float fStartTime;
        float fEndTime;
        float fAnimSpeed;
    };
    struct SEnvironmentInfo
    {
        SEnvironmentInfo()
            : bSunLinkedToTOD(true)
            , sunRotationLatitude(0)
            , sunRotationLongitude(0){}
        bool bSunLinkedToTOD;
        float sunRotationLatitude;
        float sunRotationLongitude;
    };

    // <interfuscator:shuffle>
    virtual ~ITimeOfDay(){}

    virtual int GetPresetCount() const = 0;
    virtual bool GetPresetsInfos(SPresetInfo* resultArray, unsigned int arraySize) const = 0;
    virtual bool SetCurrentPreset(const char* szPresetName) = 0;
    virtual bool AddNewPreset(const char* szPresetName) = 0;
    virtual bool RemovePreset(const char* szPresetName) = 0;
    virtual bool SavePreset(const char* szPresetName) const = 0;
    virtual bool LoadPreset(const char* szFilePath) = 0;
    virtual void ResetPreset(const char* szPresetName) = 0;

    virtual bool ImportPreset(const char* szPresetName, const char* szFilePath) = 0;
    virtual bool ExportPreset(const char* szPresetName, const char* szFilePath) const = 0;

    //! Access to variables that control time of the day appearance.
    virtual int GetVariableCount() const = 0;
    virtual bool GetVariableInfo(int nIndex, SVariableInfo& varInfo) const = 0;
    virtual void SetVariableValue(int nIndex, float fValue[3]) = 0;

    //! Editor interface.
    virtual bool InterpolateVarInRange(int nIndex, float fMin, float fMax, unsigned int nCount, Vec3* resultArray) const = 0;
    virtual uint GetSplineKeysCount(int nIndex, int nSpline) const = 0;
    virtual bool GetSplineKeysForVar(int nIndex, int nSpline, SBezierKey* keysArray, unsigned int keysArraySize) const = 0;
    virtual bool SetSplineKeysForVar(int nIndex, int nSpline, const SBezierKey* keysArray, unsigned int keysArraySize) = 0;
    virtual bool UpdateSplineKeyForVar(int nIndex, int nSpline, float fTime, float newValue) = 0;

    virtual void ResetVariables() = 0;

    //! Sets the time of the day specified in hours.
    virtual void SetTime(float fHour, bool bForceUpdate = false, bool bForceEnvUpdate = true) = 0;
    virtual float GetTime() = 0;

    //! Sun position.
    virtual void SetSunPos(float longitude, float latitude) = 0;
    virtual float GetSunLatitude() = 0;
    virtual float GetSunLongitude() = 0;

    //! Updates the current ToD.
    virtual void Tick() = 0;


    virtual void SetPaused(bool paused) = 0;

    virtual void MakeCurrentPresetFromCurrentParams() = 0;

    virtual void SetAdvancedInfo(const SAdvancedInfo& advInfo) = 0;
    virtual void GetAdvancedInfo(SAdvancedInfo& advInfo) = 0;

    //! Updates engine parameters after variable values have been changed.
    virtual void Update(bool bInterpolate = true, bool bForceUpdate = false, bool bForceEnvUpdate = true) = 0;
    //! Only updates and interpolates TOD values with.
    virtual void UpdateValues() = 0;
    //! Only updates lighting
    virtual void UpdateEnvLighting(bool forceUpdate = false) = 0;

    virtual void SetUpdateCallback(ITimeOfDayUpdateCallback* pCallback) = 0;

    virtual void BeginEditMode() = 0;
    virtual void EndEditMode() = 0;

    virtual void Serialize(XmlNodeRef& node, bool bLoading) = 0;
    virtual void Serialize(TSerialize ser) = 0;

    virtual void SetTimer(ITimer* pTimer) = 0;
    virtual void SetEnvironmentSettings(const SEnvironmentInfo& envInfo) = 0;
    virtual void LerpWith(const ITimeOfDay& other, float lerpValue, ITimeOfDay& output) const = 0;

    //! Multiplayer serialization.
    static const int NETSER_FORCESET = BIT(0);
    static const int NETSER_COMPENSATELAG = BIT(1);
    static const int NETSER_STATICPROPS = BIT(2);
    virtual void NetSerialize(TSerialize ser, float lag, uint32 flags) = 0;
};

struct ITimeOfDayUpdateCallback
{
    // <interfuscator:shuffle>
    virtual ~ITimeOfDayUpdateCallback(){}
    virtual void BeginUpdate() = 0;
    virtual bool GetCustomValue(ITimeOfDay::ETimeOfDayParamID paramID, int dim, float* pValues, float& blendWeight) = 0;
    virtual void EndUpdate() = 0;
    // </interfuscator:shuffle>
};

