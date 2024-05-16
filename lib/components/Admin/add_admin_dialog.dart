import 'package:country_code_picker/country_code_picker.dart';
import 'package:file_selector/file_selector.dart';
import 'package:find_me_admin/models/admin_model/get_all_admin.dart';
import 'package:find_me_admin/models/user_model/get_user_profile.dart';
import 'package:find_me_admin/screens/Admin/register_admin_screen.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/models/showroom/add_showroom/req_add_showroom.dart';
import 'package:find_me_admin/models/showroom/get_showroom/res_get_showroom.dart';
import 'package:find_me_admin/models/showroom/update_showroom/req_update_showroom.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/get_users_screen.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';
import 'package:image_picker/image_picker.dart';

import '../../main.dart';
import '../../models/user_model/res_get_all_user.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Constants.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/colors.dart';
import '../../utils/Extensions/text_styles.dart';
import '../../widget/selected_image_viewer.dart';

class AddAdminDialog extends StatefulWidget {
  static String tag = '/AddAdmin';

  final Admin? adminData;
  final Function()? onUpdate;
  String screen;

  AddAdminDialog({this.onUpdate, this.adminData,required this.screen});

  @override
  State<AddAdminDialog> createState() => _AddAdminDialogState();
}

class _AddAdminDialogState extends State<AddAdminDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController emailCont = TextEditingController();
  TextEditingController passwordCont = TextEditingController();
  TextEditingController adminNameCont = TextEditingController();

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.adminData != null;

    if (isUpdate) {
      emailCont.text = widget.adminData!.email.trim();
      passwordCont.text = widget.adminData!.password.trim();
      adminNameCont.text = widget.adminData!.adminName.trim();

      setState(() {});
    }
  }

  AddAdmin() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      String adminName = adminNameCont.text.trim();
      String email = emailCont.text.trim();
      String password = passwordCont.text.trim();
      var data = {'adminName': adminName, 'email': email, 'password': password};
      await registerAdmin(req: data).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          if(widget.screen=='login'){
            Navigator.pop(context);
          }else{
            Navigator.pushNamed(context, RegisterAdminScreen.route);
          }
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  UpdateAdminApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      String adminName = adminNameCont.text.trim();
      String email = emailCont.text.trim();
      String password = passwordCont.text.trim();
      var data = {'userId': widget.adminData!.id, 'adminName': adminName, 'email': email, 'password': password};
      await updateAdmin(req: data).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          Navigator.pushNamed(context, RegisterAdminScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      actionsPadding: EdgeInsets.only(right: 16, bottom: 16),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(isUpdate ? 'Update Admin' : "Add Admin Details", style: boldTextStyle(color: primaryColor, size: 20)),
          IconButton(
            icon: Icon(Icons.close),
            padding: EdgeInsets.zero,
            onPressed: () {
              Navigator.pop(context, false);
            },
          ),
        ],
      ),
      content: Observer(builder: (context) {
        return SingleChildScrollView(
          child: Stack(
            children: [
              Visibility(
                visible: !appStore.isLoading,
                child: Form(
                  key: _formKey,
                  child: SizedBox(
                    width: ResponsiveWidget.isMediumScreen(context)
                        ? getBodyWidth(context)
                        : (getBodyWidth(context) - 48) * 0.4,
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Text("Admin Name", style: primaryTextStyle()),
                            SizedBox(height: 8),
                            AppTextField(
                              controller: adminNameCont,
                              textFieldType: TextFieldType.NAME,
                              decoration: commonInputDecoration(),
                              textInputAction: TextInputAction.next,
                              errorThisFieldRequired: "This field is required",
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Text("Email", style: primaryTextStyle()),
                            SizedBox(height: 8),
                            AppTextField(
                              controller: emailCont,
                              textFieldType: TextFieldType.EMAIL,
                              decoration: commonInputDecoration(),
                              textInputAction: TextInputAction.next,
                              errorThisFieldRequired: "This field is required",
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Text("Password", style: primaryTextStyle()),
                            SizedBox(height: 8),
                            AppTextField(
                              controller: passwordCont,
                              textFieldType: TextFieldType.PASSWORD,
                              decoration: commonInputDecoration(),
                              textInputAction: TextInputAction.next,
                              errorThisFieldRequired: "This field is required",
                            ),
                          ],
                        ),
                        SizedBox(height: 40),
                      ],
                    ),
                  ),
                ),
              ),
              Visibility(visible: appStore.isLoading, child: loaderWidget()),
            ],
          ),
        );
      }),
      actions: <Widget>[
        dialogSecondaryButton("Cancel", () {
          Navigator.pop(context, false);
        }),
        SizedBox(width: 4),
        dialogPrimaryButton(isUpdate ? "Update" : "Add", () {
          isUpdate ? UpdateAdminApi() : AddAdmin();
        }),
      ],
    );
  }
}
