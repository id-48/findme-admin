import 'dart:convert';
import 'dart:typed_data';

import 'package:find_me_admin/models/event/add_event/req_add_event.dart';
import 'package:find_me_admin/models/event/res_get_all_event.dart';
import 'package:find_me_admin/models/event/update_event/req_update_event.dart';
import 'package:find_me_admin/models/places/res_get_all_place.dart';
import 'package:find_me_admin/models/user_model/res_add_user.dart';
import 'package:find_me_admin/screens/Admin/get_users_screen.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart';
import 'package:find_me_admin/models/billing/add_billing/req_billing_data.dart';
import 'package:find_me_admin/models/billing/get_billing/res_billing_data.dart';
import 'package:find_me_admin/models/billing/update_billing/req_update_billing.dart';
import 'package:find_me_admin/models/colors/add_colors/req_coloros.dart';
import 'package:find_me_admin/models/colors/get_colors/res_colors.dart';
import 'package:find_me_admin/models/colors/update_colors/req_update_colors.dart';
import 'package:find_me_admin/models/comon_res/common_response.dart';
import 'package:find_me_admin/models/designing/add_designing/req_designing.dart';
import 'package:find_me_admin/models/designing/get_designing/res_desinging.dart';
import 'package:find_me_admin/models/designing/update_designing/req_update_desinging.dart';
import 'package:find_me_admin/models/footrest/add_footrest/req_footrest.dart';
import 'package:find_me_admin/models/footrest/get_footrest/res_footrest.dart';
import 'package:find_me_admin/models/footrest/update_footrest/req_update_footrest.dart';
import 'package:find_me_admin/models/imageData/res_imageData.dart';
import 'package:find_me_admin/models/jackbase/add_jackbase/req_jackbase.dart';
import 'package:find_me_admin/models/jackbase/get_jackbase/res_jackbase.dart';
import 'package:find_me_admin/models/jackbase/update_jackbase/req_update_jackbase.dart';
import 'package:find_me_admin/models/login/res_login_user.dart';
import 'package:find_me_admin/models/product/add_product/req_add_product.dart';
import 'package:find_me_admin/models/product/get_product/res_get_product.dart';
import 'package:find_me_admin/models/product/update_product/req_update_product.dart';
import 'package:find_me_admin/models/showroom/add_showroom/req_add_showroom.dart';
import 'package:find_me_admin/models/showroom/get_showroom/res_get_showroom.dart';
import 'package:find_me_admin/models/showroom/update_showroom/req_update_showroom.dart';
import 'package:find_me_admin/screens/Admin/add_image_data__screen.dart';
import 'package:find_me_admin/utils/Extensions/toast.dart';

import '../main.dart';
import '../models/places/res_get_userwise_place.dart';
import '../models/user_model/res_get_all_user.dart';
import '../network/NetworkUtils.dart';
import '../utils/Extensions/common.dart';

Future<MultipartRequest> getMultiPartRequest(String endPoint,
    {String? baseUrl}) async {
  String url = '${baseUrl ?? buildBaseUrl(endPoint).toString()}';
  return MultipartRequest('POST', Uri.parse(url));
}

Future sendMultiPartRequest(MultipartRequest multiPartRequest,
    {Function(dynamic)? onSuccess, Function(dynamic)? onError, bool isHeader = true}) async {
  if (isHeader) {
    multiPartRequest.headers.addAll({'token': getStringAsync('TOKEN')});
  }

  await multiPartRequest.send().then((res) {
    log(res.statusCode);
    res.stream.transform(utf8.decoder).listen((value) {
      log(value);
      onSuccess?.call(jsonDecode(value));
    });
  }).catchError((error) {
    onError?.call(error.toString());
  });
}

///Login

Future<ResShowroom> loginShowroom(
    {required String showroomID, required String password}) async {
  return ResShowroom.fromJson(await handleResponse(await buildHttpResponse(
      'showroom/loginShowroom?showroomId=$showroomID&password=$password',
      method: HttpMethod.GET)));
}

/// user data

Future addUserData({
  required BuildContext context,
  required String firstName,
  required String lastName,
  required String userName,
  required String mono,
  required String address,
  required String lattitude,
  required String longtitude,
  required String countryName,
  required String countryCode,
  required String fcmToken,
  required List<Uint8List> profilePic,
}) async {
  MultipartRequest multiPartRequest = await getMultiPartRequest(
      'users/addUser');

  multiPartRequest.fields["firstName"] = firstName;
  multiPartRequest.fields["lastName"] = lastName;
  multiPartRequest.fields["userName"] = userName;
  multiPartRequest.fields["mono"] = mono;
  multiPartRequest.fields["address"] = address;
  multiPartRequest.fields["lattitude"] = lattitude;
  multiPartRequest.fields["longtitude"] = longtitude;
  multiPartRequest.fields["countryName"] = countryName;
  multiPartRequest.fields["countryCode"] = countryCode;
  multiPartRequest.fields["fcmToken"] = fcmToken;

  if (profilePic.isNotEmpty) {
    multiPartRequest.files.add(
        MultipartFile.fromBytes('profilePic', profilePic[0],
            filename: DateTime
                .now()
                .microsecondsSinceEpoch
                .toString() + ".png"));
  }

  await sendMultiPartRequest(multiPartRequest, onSuccess: (data) async {
    appStore.setLoading(false);
    if (data != null) {
      ResAddUser res = ResAddUser.fromJson(data);

      print("Response updateInquiry --> ${res.toJson()}");
      if (res.status == true) {
        if (res.token.isNotEmpty) {
          setString('TOKEN', res.token);
        }
        ToastUtils.showCustomToast(context, res.message, "success");

        Navigator.pushNamed(context, GetUsersScreen.route);
      } else {
        ToastUtils.showCustomToast(context, res.message, "warning");
      }
    }
    return data;
  }, onError: (error) {
    ToastUtils.showCustomToast(context, error.toString(), "warning");
  }, isHeader: false);
}

Future updateUserData({
  required BuildContext context,
  required String userId,
  required String firstName,
  required String lastName,
  required String userName,
  required String mono,
  required String address,
  required String lattitude,
  required String longtitude,
  required String countryName,
  required String countryCode,
  required String fcmToken,
  required List<Uint8List> profilePic,
}) async {
  MultipartRequest multiPartRequest = await getMultiPartRequest(
      'users/updateUser');

  multiPartRequest.fields["userId"] = userId;
  multiPartRequest.fields["firstName"] = firstName;
  multiPartRequest.fields["lastName"] = lastName;
  multiPartRequest.fields["userName"] = userName;
  multiPartRequest.fields["mono"] = mono;
  multiPartRequest.fields["address"] = address;
  multiPartRequest.fields["lattitude"] = lattitude;
  multiPartRequest.fields["longtitude"] = longtitude;
  multiPartRequest.fields["countryName"] = countryName;
  multiPartRequest.fields["countryCode"] = countryCode;
  multiPartRequest.fields["fcmToken"] = fcmToken;

  if (profilePic.isNotEmpty) {
    multiPartRequest.files.add(
        MultipartFile.fromBytes('profilePic', profilePic[0],
            filename: DateTime
                .now()
                .microsecondsSinceEpoch
                .toString() + ".png"));
  }

  await sendMultiPartRequest(multiPartRequest, onSuccess: (data) async {
    appStore.setLoading(false);
    if (data != null) {
      CommonResponse res = CommonResponse.fromJson(data);

      print("Response updateInquiry --> ${res.toJson()}");
      if (res.status == true) {
        ToastUtils.showCustomToast(context, res.message, "success");

        Navigator.pushNamed(context, GetUsersScreen.route);
      } else {
        ToastUtils.showCustomToast(context, res.message, "warning");
      }
    }
    return data;
  }, onError: (error) {
    ToastUtils.showCustomToast(context, error.toString(), "warning");
  }, isHeader: true);
}

Future<ResGetAllUser> getAllUsers({
  required int limit,
  required int page,
}) async {
  return ResGetAllUser.fromJson(await handleResponse(
      await buildHttpResponse('users/getAllUser?limit=$limit&pageNo=$page',
          method: HttpMethod.GET)));
}

Future<CommonResponse> deleteUserApi({required String userId}) async {
  return CommonResponse.fromJson(
      await handleResponse(await buildHttpResponse(
          'users/deleteUser?userId=$userId', method: HttpMethod.GET)));
}

/// event data
Future<CommonResponse> addEvent({required dynamic req}) async {
  print('req: ${req}');
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse(
          'events/addEvent', request: req, method: HttpMethod.POST)));
}

Future<CommonResponse> updateEvent({required dynamic req}) async {
  print('req ::${req.toString()}');
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse(
          'events/updateEvent', request: req, method: HttpMethod.POST)));
}

Future<ResGetAllEvents> getAllEvents({
  int? limit,
  int? page,
}) async {
  return ResGetAllEvents.fromJson(await handleResponse(await buildHttpResponse(
      'events/getAllEvent${limit != null ? "?limit=$limit" : ""}${page != null
          ? "&pageNo=$page"
          : ""}',
      method: HttpMethod.GET)));
}

Future<CommonResponse> deleteEvents({required String eventId}) async {
  return CommonResponse.fromJson(
      await handleResponse(await buildHttpResponse(
          'events/deleteEvent?eventId=$eventId', method: HttpMethod.GET)));
}

///place Data

Future<CommonResponse> addPlaceData({required dynamic req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse(
          'places/addPlace', request: req, method: HttpMethod.POST)));
}

Future<CommonResponse> updatePlaceData({required dynamic req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse(
          'places/updatePlace', request: req, method: HttpMethod.POST)));
}

Future<ResGetAllPlace> getAllPlaces({
  int? limit,
  int? page,
}) async {
  return ResGetAllPlace.fromJson(await handleResponse(await buildHttpResponse(
      'places/getAllPlace${limit != null ? "?limit=$limit" : ""}${page != null
          ? "&pageNo=$page"
          : ""}',
      method: HttpMethod.GET)));
}

Future<ResUserWisePlaces> getUserWisePlaces({
  int? limit,
  int? page,
  String? mono,
}) async {
  return ResUserWisePlaces.fromJson(await handleResponse(await buildHttpResponse(
      'places/getUserWisePlace?mono=$mono${limit != null ? "&limit=$limit" : ""}${page != null
          ? "&pageNo=$page"
          : ""}',
      method: HttpMethod.GET)));
}

Future<ResGetAllPlace> getUserWisePlace({
  int? limit,
  int? page,
}) async {
  return ResGetAllPlace.fromJson(await handleResponse(await buildHttpResponse(
      'places/getAllPlace${limit != null ? "?limit=$limit" : ""}${page != null
          ? "&pageNo=$page"
          : ""}',
      method: HttpMethod.GET)));
}

Future<CommonResponse> deletePlaces({required String placeId}) async {
  return CommonResponse.fromJson(
      await handleResponse(await buildHttpResponse(
          'places/deletePlace?placeId=$placeId', method: HttpMethod.GET)));
}

///Footrest Data

Future<CommonResponse> addFootrest({required ReqFootrest req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('footRest/addFootRest', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<CommonResponse> updateFootrest({required ReqUpdateFootrest req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('footRest/updateFootRest', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<ResFootrest> getFootrest({
  int? limit,
  int? page,
}) async {
  return ResFootrest.fromJson(await handleResponse(await buildHttpResponse(
      'footRest/getFootRest${limit != null ? "?limit=$limit" : ""}${page != null
          ? "&pageNo=$page"
          : ""}',
      method: HttpMethod.GET)));
}

Future<CommonResponse> deleteFootrest({required String footRestId}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('footRest/deleteFootRest?footRestId=$footRestId',
          method: HttpMethod.GET)));
}

///JackBase Data

Future<CommonResponse> addJackBase({required ReqJackbase req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('jackBase/addJackBase', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<CommonResponse> updateJackBase({required ReqUpdateJackbase req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('jackBase/updateJackBase', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<ResJackbase> getJackBase({
  int? limit,
  int? page,
}) async {
  return ResJackbase.fromJson(await handleResponse(await buildHttpResponse(
      'jackBase/getJackBase${limit != null ? "?limit=$limit" : ""}${page != null
          ? "&pageNo=$page"
          : ""}',
      method: HttpMethod.GET)));
}

Future<CommonResponse> deleteJackBase({required String jackBaseId}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('jackBase/deleteJackBase?jackBaseId=$jackBaseId',
          method: HttpMethod.GET)));
}

///Image Data

Future addImageData({
  required BuildContext context,
  required List<Uint8List> image,
}) async {
  ///  multi
  MultipartRequest multiPartRequest = await getMultiPartRequest(
      'imageData/addImageData');

  if (image.isNotEmpty) {
    for (int i = 0; i < image.length; i++) {
      multiPartRequest.files.add(MultipartFile.fromBytes('image', image[i],
          filename: DateTime
              .now()
              .microsecondsSinceEpoch
              .toString() + ".png"));
    }
  }
  print('REQ Image data: ${multiPartRequest
      .fields}  \n files -->${multiPartRequest.files}');
  await sendMultiPartRequest(multiPartRequest, onSuccess: (data) async {
    appStore.setLoading(false);
    if (data != null) {
      CommonResponse res = CommonResponse.fromJson(data);

      if (res.status == true) {
        ToastUtils.showCustomToast(context, res.message, "success");

        Navigator.pushNamed(context, ImageDataScreen.route);
      } else {
        ToastUtils.showCustomToast(context, res.message, "warning");
      }
    }
    return data;
  }, onError: (error) {
    ToastUtils.showCustomToast(context, error.toString(), "warning");
  });
}

Future updateImageData({
  required BuildContext context,
  required String imageDataId,
  required List<Uint8List> image,
}) async {
  MultipartRequest multiPartRequest = await getMultiPartRequest(
      'imageData/updateImageData');

  multiPartRequest.fields["imageDataId"] = imageDataId;

  if (image.isNotEmpty) {
    for (int i = 0; i < image.length; i++) {
      multiPartRequest.files.add(MultipartFile.fromBytes('image', image[i],
          filename: DateTime
              .now()
              .microsecondsSinceEpoch
              .toString() + ".png"));
    }
  }

  await sendMultiPartRequest(multiPartRequest, onSuccess: (data) async {
    appStore.setLoading(false);
    if (data != null) {
      CommonResponse res = CommonResponse.fromJson(data);

      print("Response updateInquiry --> ${res.toJson()}");
      if (res.status == true) {
        ToastUtils.showCustomToast(context, res.message, "success");

        Navigator.pushNamed(context, ImageDataScreen.route);
      } else {
        ToastUtils.showCustomToast(context, res.message, "warning");
      }
    }
    return data;
  }, onError: (error) {
    ToastUtils.showCustomToast(context, error.toString(), "warning");
  });
}

Future<ResImageData> getImageData({
  int? limit,
  int? page,
}) async {
  return ResImageData.fromJson(await handleResponse(await buildHttpResponse(
      'imageData/getImageData${limit != null ? "?limit=$limit" : ""}${page !=
          null ? "&pageNo=$page" : ""}',
      method: HttpMethod.GET)));
}

Future<CommonResponse> deleteImageData({required String imageId}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('imageData/deleteImageData?imageId=$imageId',
          method: HttpMethod.GET)));
}

///Product Data

Future<CommonResponse> addProduct({required ReqAddProduct req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('product/addProduct', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<CommonResponse> updateProduct({required ReqUpdateProduct req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('product/updateProduct', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<ResGetProduct> getProduct({
  required int limit,
  required int page,
}) async {
  return ResGetProduct.fromJson(await handleResponse(
      await buildHttpResponse('product/getProduct?limit=$limit&pageNo=$page',
          method: HttpMethod.GET)));
}

Future<ResGetProduct> getSearchProduct({
  required String searchVal,
}) async {
  return ResGetProduct.fromJson(await handleResponse(
      await buildHttpResponse('product/searchProduct?productName=$searchVal',
          method: HttpMethod.GET)));
}

Future<CommonResponse> deleteProduct({required String productId}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('product/deleteProduct/?productId=$productId',
          method: HttpMethod.GET)));
}

///Billing Data

Future<CommonResponse> addBilling({required ReqBilling req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('billing/addBilling', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<CommonResponse> updateBilling({required ReqUpdateBilling req}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('billing/updateBilling', request: req.toJson(),
          method: HttpMethod.POST)));
}

Future<ResBilling> getBilling({
  required int limit,
  required int page,
}) async {
  return ResBilling.fromJson(await handleResponse(
      await buildHttpResponse('billing/getBilling?limit=$limit&pageNo=$page',
          method: HttpMethod.GET)));
}

Future<ResBilling> getShowroomWiseBilling(
    {required int limit, required int page, required String showroomId}) async {
  return ResBilling.fromJson(await handleResponse(await buildHttpResponse(
      'billing/showroomWiseBilling?limit=$limit&pageNo=$page&showroomId=$showroomId',
      method: HttpMethod.GET)));
}

Future<CommonResponse> deleteBilling({required String billingId}) async {
  return CommonResponse.fromJson(await handleResponse(
      await buildHttpResponse('billing/deleteBilling?billingId=$billingId',
          method: HttpMethod.GET)));
}
